//Eduardo Porto e Johannes Portz
//T1 Teste e Confiabilidade de Sistemas
#include <hf-risc.h>
#include <hf-unit.h>
#include <fixed.h>

// function under test
fixed_t fix_cos(fixed_t rad);

// list of individual tests
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();

// main test
void hfunit_run_tests_fix_cos(){
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
}

//
void test1(){
	fixed_t expected = -1;
	fixed_t received = fix_cos(-FIX_PI);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n\n", expected, received);
	printBits(8, &expected);
	printBits(8, &received);
}

//
void test2(){
	fixed_t expected = -1;
	fixed_t received = fix_cos(FIX_PI);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n\n", expected, received);
}

//
void test3(){
	fixed_t expected = 1;
	fixed_t received = fix_cos(0);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n\n", expected, received);
}

//
void test4(){
	fixed_t expected = 1;
	fixed_t received = fix_cos(0.0000001);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n\n", expected, received);
}

//
void test5(){
	fixed_t expected = 0;
	fixed_t received = fix_cos(FIX_HALF_PI);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n\n", expected, received);
}

//
void test6(){
	fixed_t expected = 0;
	fixed_t received = fix_cos(FIX_FOURTH_PI);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n\n", expected, received);
}

//
void test7(){
	fixed_t expected = 0;
	fixed_t received = fix_cos(FIX_TWO_PI);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n\n", expected, received);
}

//
void test8(){
	fixed_t expected = 0;
	fixed_t received = fix_cos(2);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n\n", expected, received);
}