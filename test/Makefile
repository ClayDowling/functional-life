CFLAGS = `pkg-config --cflags check` -g -std=c99 -Wconversion
LIBS = `pkg-config --libs check`
VPATH=..

TEST_SOURCE = $(wildcard test_*.c)
TEST_BASE = $(basename $(TEST_SOURCE))
TEST_OBJECTS = $(addsuffix .o, $(TEST_BASE))

OBJECTS_UNDER_TEST = board.o neighbor.o neighbor_board.o life_rules.o game.o \
	board_iterator.o

FRAMEWORK_OBJECTS = testmain.o

all: test_life
	./test_life

full: all memtest

test_life: $(OBJECTS_UNDER_TEST) $(TEST_OBJECTS) $(FRAMEWORK_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

memtest: test_life
	CK_FORK=no valgrind --leak-check=full ./test_life

clean:
	rm -f *.o
	rm -rf *.dSYM
	rm -f test_life
