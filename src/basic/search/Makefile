DEFINES += -D_GNU_SOURCE
CFLAGS = -I../../lib/
LDFLAGS = -L../../lib/ -lalgor

OBJS = binary_search \
	   graph_search

all: $(OBJS)

binary_search: binary_search.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ binary_search.o

graph_search: graph_search.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ graph_search.o

clean:
	rm -f *.o $(OBJS)
