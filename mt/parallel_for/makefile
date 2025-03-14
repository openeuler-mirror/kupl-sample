CC = clang++

OBJS = parallel_for.cpp
TARGET = parallel_for

LDFLAGS = -lkupl

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	KUPL_EXECUTOR_BACKEND=pthread KUPL_SCHED_POLICY=sspe taskset -c 0-7 ./$(TARGET)

clean:
	rm -f $(TARGET)