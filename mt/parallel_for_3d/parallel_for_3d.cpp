/*
    KUPL parallel for 3d 并行 Demo
    编译命令: clang++ parallel_for_3d.cpp -o parallel_for_3d -lkupl
    运行命令: KUPL_EXECUTOR_BACKEND=pthread KUPL_SCHED_POLICY=sspe taskset -c 0-7 ./parallel_for_3d
*/

#include <stdio.h>
#include "kupl.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define LENGTH 10
#define WIDTH 7
#define HEIGHT 5

static int A[LENGTH][WIDTH][HEIGHT];
static int B[LENGTH][WIDTH][HEIGHT];
int C[LENGTH][WIDTH][HEIGHT];

static void array_3d_init() {
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            for (int k = 0; k < HEIGHT; k++) {
                A[i][j][k] = i + j + k;
                B[i][j][k] = i + j + k;
                C[i][j][k] = 0;
            }
        }
    }
}

static bool array_3d_check() {
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            for (int k = 0; k < HEIGHT; k++) {
                if (C[i][j][k] != A[i][j][k] + B[i][j][k]) {
                    return false;
                }
            }
        }
    }
    return true;
}

static inline void task_int_loop3d(kupl_nd_range_t *nd_range, void *args, int tid, int tnum)
{
    // 打印每个线程每次任务执行的for循环LOOP范围
    printf("tid: %d\n--range0: lower %zu upper %zu\n--range1: lower %zu upper %zu\n--range2: lower %zu upper %zu\n",
           tid, nd_range->nd_range[0].lower, nd_range->nd_range[0].upper, nd_range->nd_range[1].lower,
           nd_range->nd_range[1].upper, nd_range->nd_range[2].lower, nd_range->nd_range[2].upper);
    for (int i = nd_range->nd_range[0].lower;
         i < nd_range->nd_range[0].upper; i += nd_range->nd_range[0].step) {
        for (int j = nd_range->nd_range[1].lower;
             j < nd_range->nd_range[1].upper; j += nd_range->nd_range[1].step) {
            for (int k = nd_range->nd_range[2].lower;
                 k < nd_range->nd_range[2].upper; k += nd_range->nd_range[2].step) {
                C[i][j][k] = A[i][j][k] + B[i][j][k];
            }
        }
        
    }
}

int main()
{
    array_3d_init();
    const int NUM_THREADS = kupl_get_num_executors();
    printf("num_thread: %d\n", NUM_THREADS);
    kupl_nd_range_t range;
    range.dim = 3;
    int upper_list[3] = {LENGTH, WIDTH, HEIGHT};
    for (int i = 0; i < range.dim; i++) {
        range.nd_range[i].lower = 0;
        range.nd_range[i].upper = upper_list[i];
        range.nd_range[i].step = 1;
        range.nd_range[i].blocksize = 1;
    }

    int executor[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        executor[i] = i;
    }
    kupl_egroup_h eg = kupl_egroup_create(executor, NUM_THREADS);

    kupl_parallel_for_desc_t desc = {
        .range = &range,
        .concurrency = NUM_THREADS,
        .egroup = eg,
        .policy = KUPL_LOOP_POLICY_STATIC      // 此处可切换不同的策略，观察执行效果，对比static与dynamic策略的执行区别
    };
    
    kupl_parallel_for(&desc, task_int_loop3d, nullptr);
    bool res = array_3d_check();
    printf("parallel for 3d result: %d\n", res);

    kupl_egroup_destroy(eg);
    return 0;
}