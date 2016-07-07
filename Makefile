CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Werror -Wextra
DEBUG_FLAGS = -g -DDEBUG

run-test : build-debug
	./test

run-debug : build-debug
	./test

run-gdb : build-debug
	gdb ./test

run-valgrind : build-debug
	valgrind --leak-check=yes --show-reachable=yes --tool=memcheck ./test

build-debug : CFLAGS += $(DEBUG_FLAGS)
build-debug : verify deque.o test.o deque.h
	$(CC) $(CFLAGS) test.o deque.o -o test

deque.o : deque.c deque.h
	$(CC) $(CFLAGS) -c deque.c

test.o : test.c deque.h
	$(CC) $(CFLAGS) -c test.c

clean :
	rm *.o test

submit : verify
	tar -czf deque_submission.tar.gz deque.c

verify : verify.sh
	@/bin/bash verify.sh

