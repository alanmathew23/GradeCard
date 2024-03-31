CC = gcc
CFLAGS = -Wall -Wextra -I.

SRCS = Main_file.c student_data.c
OBJS = $(SRCS:.c=.o)
HEADER = input_data.h
EXECUTABLE = Grade_card

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	del $(EXECUTABLE) $(OBJS)