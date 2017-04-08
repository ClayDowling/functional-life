.PHONY: all test clean

CFLAGS = -std=c99 -Wconversion

SOURCES=$(wildcard *.c)
BASES=$(basename $SOURCES)
OBJECTS=$(addsuffix .o, $BASES)

all: test life

clean:
	$(MAKE) -C test clean
	rm -f *.o
	rm -f life

test:
	$(MAKE) -C test full

life: $(OBJECTS)
	$(CC) -o $@ $^
