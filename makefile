CC = gcc
CFLAGS = -Wall
TARGET = main
SRCS = main.c validation.c marks.c grade.c fileio.c statistics.c
OBJS = $(SRCS:.c=.o)
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all
