CC=gcc
CFLAGS=-Wall -g
lib=libavl.so
BINS=test

.PHONY: test

test: test.c
	$(CC) $^ -o test -lavl

lib: avl.c avl.h avl_utils.c
	$(CC) -fpic -shared -lc avl.c -o libavl.so

clean:
	rm $(BINS) *.o *.gch *.so
