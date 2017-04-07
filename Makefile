.PHONY: all test clean

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
