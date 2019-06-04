.SUFFIXES : .c.o
CC = gcc
CFLAGS = -g

OBJS1 = main.o test1.o
OBJS2 = main.o test2.o
OBJS3 = main.o test3.o

all : test1 test2 test3

test1: $(OBJS1)
	$(CC) -o $@ $(OBJS1)
test2: $(OBJS2)
	$(CC) -o $@ $(OBJS2)
test3: $(OBJS3)
	$(CC) -o $@ $(OBJS3)
