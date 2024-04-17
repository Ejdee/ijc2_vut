CC = gcc
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra -fPIC
EXECUTABLE = tail htab_main io_test wordcount wordcount-dynamic wordcount-dhash_size wordcount-dhash_size-dynamic
HTAB_OBJECTS = htab_init.o htab_size.o htab_bucket_size.o htab_find.o htab_lookup_add.o htab_hash_function.o htab_erase.o htab_free.o htab_clear.o htab_statistics.o htab_for_each.o resize_hash_table.o htab_load_factor.o

all: $(EXECUTABLE) libhtab.a libhtab.so

libhtab.a: $(HTAB_OBJECTS)
	ar crs $@ $^

libhtab.so: $(HTAB_OBJECTS)
	$(CC) -shared -fPIC $^ -o $@

wordcount: wordcount.o libhtab.a io.o
	$(CC) $(CFLAGS) -o $@ -static wordcount.o io.o -L. -lhtab

wordcount-dynamic: wordcount.o libhtab.so io.o
	$(CC) $(CFLAGS) -o $@ wordcount.o io.o -L. -lhtab

wordcount-dhash_size-dynamic: wordcount-dhash_size.o libhtab.so io.o
	$(CC) $(CFLAGS) -o $@ wordcount-dhash_size.o io.o -L. -lhtab

wordcount-dhash_size: wordcount-dhash_size.o libhtab.a io.o
	$(CC) $(CFLAGS) -static -o $@ wordcount-dhash_size.o io.o -L. -lhtab

tail: tail.o error.o
	$(CC) $(CFLAGS) -o $@ $^

htab_main: htab_main.o $(HTAB_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

io_test: io_test.o io.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXECUTABLE) *.a *.so

-include deps