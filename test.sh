#!/bin/sh
gcc -o test0 tests/test0.c;
gcc -o test1 tests/test1.c;
gcc -o test2 tests/test2.c;
gcc -o test3 tests/test3.c;
gcc -o test3bis tests/test3bis.c;
gcc -o test4 tests/test4.c;
gcc -o test5 tests/test5.c -L. -lft_malloc;
