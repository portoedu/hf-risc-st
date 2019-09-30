#!/bin/bash

cd ./software/tests/math/ceil/
cppcheck test.c
make test
gcov hf_riscv_sim.c

cd ../floor/
cppcheck test.c
make test
gcov hf_riscv_sim.c

cd ../..
cd ./libc/strcpy/
cppcheck test.c
make test
gcov hf_riscv_sim.c

cd ../strlen/
cppcheck test.c
make test
gcov hf_riscv_sim.c

cd ../..
cd ./fixed/fix_cos/
cppcheck test.c
make test
gcov hf_riscv_sim.c

cd ../fix_sen/
cppcheck test.c
make test
gcov hf_riscv_sim.c

cd ../..
cd ./matrix/get_line/
cppcheck test.c
make test
gcov hf_riscv_sim.c

cd ../get_column/
cppcheck test.c
make test
gcov hf_riscv_sim.c
