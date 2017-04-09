# functional-life
Conway's Game of Life implemented as Test Driven, functional style C code.

## The Game

[Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) is
a mathematical game that begs for computerization.  It's also a very common
coding kata.  Because of it's simplicity, it's a good way to try out new
coding styles (like maybe functional programming) or even new languages.

## Requirements

- GNU Make.  If you are on a BSD system this is the package gmake.  On Windows
  you will need to install the mingw suite of tools.

- 'pkg-config' to build tests (on by default).

- [check](https://libcheck.github.io/check/), a library
  for test driven development in C.

- A C99 compliant C compiler.  [clang](https://clang.llvm.org/),
  [gcc](https://gcc.gnu.org/), or [mingw-w64](http://mingw-w64.org/doku.php)
  are all suitable.
