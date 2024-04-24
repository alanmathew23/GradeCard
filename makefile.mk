CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = main.c student.c
OBJS = $(SRCS:.c=.o)
EXEC = grade_card

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
