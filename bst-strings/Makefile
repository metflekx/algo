OBJS=main.o
CC=gcc

all: main

.PHONY: all

*.o: *.c
	$(CC) -c $^ -o $@

main: $(OBJS)
	$(CC) $^ -o $@

clean: $(OBJS)
	rm -f $^ && rm -f main

notes:
	cat /home/dog/code/algo/notes.text
