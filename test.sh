#!/bin/bash

cd ./software/tests/math/ceil/
cppcheck test.c
make test
cd ../floor/
cppcheck test.c
make test

cd ../..
cd ./libc/strcpy/
cppcheck test.c
make test
cd ../strlen/
cppcheck test.c
make test

cd ../..
cd ./fixed/fix_cos/
cppcheck test.c
make test
cd ../fix_sen/
cppcheck test.c
make test

cd ../..
cd ./matrix/get_line/
cppcheck test.c
make test
cd ../get_column/
cppcheck test.c
make test
