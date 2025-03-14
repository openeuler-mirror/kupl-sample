# kupl-sample

#### 介绍
kupl_sample 提供了一组使用 kupl 库的用例

#### 软件架构
每个大目录下有多个小目录，每个小目录中有对应的用例（demo 源码，makefile 文件，readme 说明）
example：综合用例
    mt_gemm_fp64 GEMM 算子开发实践
memory: 数据管理
    memcpy 数据拷贝
    memcpy_async 异步数据拷贝
    memcpy2d 数据拷贝 2D
    shm 共享内存
mma: 矩阵编程
    mma_fp64 矩阵乘加
mt: 众核并行
    graph 计算机图编程
    parallel_for 并行 for 循环
    queue 多队列编程

#### 安装教程

1.  安装最新的 HPCKit
    下载地址：https://www.hikunpeng.com/developer/hpc/hpckit-download
    安装指南：https://www.hikunpeng.com/document/detail/zh/kunpenghpcs/hpckit/instg/topic_0000001806090516.html
    开发指南：https://www.hikunpeng.com/document/detail/zh/kunpenghpcs/hpckit/devg/KunpengHPCKit_developer_003.html
2.  下载本文件
3.  到目标小目录下
    1、按代码开头的注释说明进行编译和执行
    2、使用 make 指令进行编译，使用 make run 运行

#### 使用说明

1.  本用例仅供参考，具体使用方法请看 HPCKit 官方手册
2.  本用例提供两种不同的编译/执行方式，用户可以自由选择

#### 参与贡献

1.  Fork 本仓库
2.  新建 master 分支
3.  提交代码
4.  新建 Pull Request


#### 特技

1.  使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md
2.  Gitee 官方博客 [blog.gitee.com](https://blog.gitee.com)
3.  你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解 Gitee 上的优秀开源项目
4.  [GVP](https://gitee.com/gvp) 全称是 Gitee 最有价值开源项目，是综合评定出的优秀开源项目
5.  Gitee 官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)
6.  Gitee 封面人物是一档用来展示 Gitee 会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)
