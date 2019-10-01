#!/bin/bash

cd ./software/tests/math/ceil/
make test
cppcheck test.c > cppcheck.log
gcov hf_riscv_sim.c >gcov.log
gprof ./hf_riscv_sim gmon.out >gprof.log
head cppcheck.log -n 200
head gcov.log -n 200
head gprof.log -n 200
wait

cd ../floor/
make test
cppcheck test.c > cppcheck.log
gcov hf_riscv_sim.c >gcov.log
gprof ./hf_riscv_sim gmon.out >gprof.log
head cppcheck.log -n 200
head gcov.log -n 200
head gprof.log -n 200


cd ../..
cd ./libc/strcpy/
make test
cppcheck test.c > cppcheck.log
gcov hf_riscv_sim.c >gcov.log
gprof ./hf_riscv_sim gmon.out >gprof.log
head cppcheck.log -n 200
head gcov.log -n 200
head gprof.log -n 200


cd ../strlen/
make test
cppcheck test.c > cppcheck.log
gcov hf_riscv_sim.c >gcov.log
gprof ./hf_riscv_sim gmon.out >gprof.log
head cppcheck.log -n 200
head gcov.log -n 200
head gprof.log -n 200


cd ../..
cd ./fixed/fix_cos/
make test
cppcheck test.c > cppcheck.log
gcov hf_riscv_sim.c >gcov.log
gprof ./hf_riscv_sim gmon.out >gprof.log
head cppcheck.log -n 200
head gcov.log -n 200
head gprof.log -n 200


cd ../fix_sen/
make test
cppcheck test.c > cppcheck.log
gcov hf_riscv_sim.c >gcov.log
gprof ./hf_riscv_sim gmon.out >gprof.log
head cppcheck.log -n 200
head gcov.log -n 200
head gprof.log -n 200


cd ../..
cd ./matrix/get_line/
make test
cppcheck test.c > cppcheck.log
gcov hf_riscv_sim.c >gcov.log
gprof ./hf_riscv_sim gmon.out >gprof.log
head cppcheck.log -n 200
head gcov.log -n 200
head gprof.log -n 200


cd ../get_column/
make test
cppcheck test.c > cppcheck.log
gcov hf_riscv_sim.c >gcov.log
gprof ./hf_riscv_sim gmon.out >gprof.log
head cppcheck.log -n 200
head gcov.log -n 200
head gprof.log -n 200

