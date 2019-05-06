DEFINES += -D_GNU_SOURCE
CFLAGS = -I../../lib/
LDFLAGS = -L../../lib/ -lalgor

OBJS = bubble_sort		\
		insertion_sort	\
		shell_sort		\
		merge_sort		\
		quick_sort		\
		counting_sort

all: $(OBJS)

bubble_sort: bubble_sort.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ bubble_sort.o

insertion_sort: insertion_sort.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ insertion_sort.o

shell_sort: shell_sort.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ shell_sort.o

merge_sort: merge_sort.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ merge_sort.o

quick_sort: quick_sort.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ quick_sort.o

counting_sort: counting_sort.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ counting_sort.o

clean:
	rm -f *.o $(OBJS)
