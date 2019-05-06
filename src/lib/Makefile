PACKAGE_VERSION=1.0

OBJ=util.o		\
	list.o 		\
	heap.o		\
	bs_tree.o	\
	graph.o

DEFINES += -D_GNU_SOURCE
CFLAGS = -g -fPIC
CFLAGS += -Wall -Wstrict-prototypes  -Wmissing-prototypes

all: shared static

LIB_VERSION=1.0
shared: $(OBJ)
	gcc -shared -Wl,--enable-new-dtags              \
		-Wl,--soname,libalgor.so.$(LIB_VERSION)     \
        $(OBJ) $(LDFLAGS)                           \
        -o libalgor.so

static: $(OBJ)
	$(AR) rcs libalgor.a $(OBJ)

install:
	rm -f /usr/lib64/{libalgor.a, libalgor.so}
	rm -f /usr/lib64/libalgor.so.${PACKAGE_VERSION}
	cp libalgor.a /usr/lib64/
	cp libalgor.so /usr/lib64/
	ln -s /usr/lib64/libalgor.so /usr/lib64/libalgor.so.${PACKAGE_VERSION}

clean:
	rm -f *.o *.a *.so
