.SUFFIXES : .c .o
CC = gcc
CFLAGS = -g -c

all: bubblesort_length bubblesort_alpha strcpy_ex make-a-list \
search-a-char

bubblesort_length :
	$(CC) -o bubblesort_length bubblesort_length.c

bubblesort_alpha :
	$(CC) -o bubblesort_alpha bubblesort_alpha.c

strcpy_ex :
	$(CC) -o strcpy_ex strcpy_ex.c

make-a-list :
	$(CC) -o make-a-list make-a-list.c

search-a-char :
	$(CC) -o search-a-char search-a-char.c

clean:
	rm -rf $(OBJS) $(TARGET) core
 
dep:
	$(CC) -M $(SRCS)
