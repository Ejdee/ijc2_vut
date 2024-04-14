CC = gcc
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra
EXECUTABLE = tail htab_main
HTAB_OBJECTS = htab_init.o htab_size.o htab_bucket_size.o htab_find.o htab_lookup_add.o htab_hash_function.o htab_erase.o htab_free.o htab_clear.o

all: $(EXECUTABLE)

tail: tail.o error.o
	$(CC) $(CFLAGS) -o $@ $^

htab_main: htab_main.o $(HTAB_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXECUTABLE)

-include deps