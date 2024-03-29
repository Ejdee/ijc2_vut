CC = gcc
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra
EXECUTABLE = tail

all: $(EXECUTABLE)

tail: tail.o
	$(CC) $(CFLAGS) -o $@ $^

tail.o: tail.c tail.h
error.o: error.c error.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXECUTABLE)