# hrPkg
Local package manager

This is a very simple package manager I wrote in C to kill time. It's based on a package directory containing the necessary
scripts for building and installing files.

## Building
To build hrPkg, you have to have:
- A working C compiler
- A working C library
- GNU Make

Simply do `make all` to build with GNU Make. Sometimes you might want to edit Makefile to suit your system.
Some Make flags:
- OPT: optimization level

## Using
After building, use `./hrpkg -[IBFVCL] [package 1] [package 2] ...` to build/install/fetch the packages.
- I: Install packages.
- B: Build packages.
- F: Fetch packages.

At the time, only -B is implemented.


Some useful flags:
- V: Enable verbosity. I recommend using this 10/10 times. It lets you check the content of the scripts before installing
and outputs meaningful errors.
- L: Make installation local to the current directory instead to the directory specified in the C files. However installing isn't
implemented yet so...
- C: Check the packages without installing/building. (Not implemented yet)

An example of `raylib` package is provided. You can run `./hrpkg -BV raylib` to try build it.
