#! /bin/bash

as --32 -g -o ex1-13.o ex1-13.S
ld -m elf_i386 -o ex1-13 -lc -dynamic-linker /lib/ld-linux.so.2 -e main ex1-13.o
