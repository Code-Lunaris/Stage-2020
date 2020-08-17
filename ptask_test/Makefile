CC      = gcc

PTASK_PATH = ../ptask/src


CFLAGS = -pthread -Wall

LIBFLAGS = -L .
LIBFLAGS += -l ptask

TOUS := test

tout: ${TOUS}

test.o : test.c
	${CC} -I ${PTASK_PATH} -c $<

test : test.o
	${CC} -o $@ $< ${CFLAGS} ${LIBFLAGS}

clean: 
	rm -f core *.o

realclean: clean
	rm -f test