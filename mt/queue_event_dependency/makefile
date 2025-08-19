CC = clang++

OBJS = queue_event_dependency.cpp
TARGET = queue_event_dependency

LDFLAGS = -lkupl

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	KUPL_SCHED_POLICY=mq KUPL_EXECUTOR_BACKEND=pthread ./$(TARGET)

clean:
	rm -f $(TARGET)