SUBDIRS = offer2Code leetCode

all: SUBDIRS

SUBDIRS:
	for i in $(SUBDIRS); do \
		$(MAKE) $(MFLAGS) -C $$i; \
	done

clean:
	for i in $(SUBDIRS); do \
		$(MAKE) clean -C $$i; \
	done
