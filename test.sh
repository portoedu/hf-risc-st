#!/bin/bash

cd ./software/tests/math/ceil/
make test
cd ../floor/
make test

cd ../..
cd ./libc/strcpy/
make test
cd ../strlen/
make test

cd ../..
cd ./fixed/fix_cos/
make test
cd ../fix_sen/
make test

cd ../..
cd ./matrix/get_line/
make test
cd ../get_column/
make test
