DEFINES += -D_GNU_SOURCE
CFLAGS = -I../../lib/
LDFLAGS = -L../../lib/ -lalgor

OBJS = shortest_path

all: $(OBJS)

shortest_path: shortest_path.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ shortest_path.o

clean:
	rm -f *.o $(OBJS)
