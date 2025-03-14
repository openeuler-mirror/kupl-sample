CC = clang++

OBJS = memcpy_async.cpp
TARGET = memcpy_async

LDFLAGS = -lkupl

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	KUPL_SCHED_POLICY=mq taskset -c 2 ./$(TARGET)

clean:
	rm -f $(TARGET)