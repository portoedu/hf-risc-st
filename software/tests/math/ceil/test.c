//Eduardo Porto e Johannes Portz
//T1 Teste e Confiabilidade de Sistemas
#include <hf-risc.h>
#include <hf-unit.h>

// function under test
float ceil(float d);

// list of individual tests
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();

// main test
void hfunit_run_tests_ceil(){
	test1();
	test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
}

// 
void test1(){
	float expected = 1.0;
	float received = ceil(0x00000001);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printf("ex: %d, rc: %d\n", (int)expected, (int)received);
}

// 
void test2(){
	float expected = 1.0;
	float entrada = 1.0;
	float received = ceil(entrada);
	//hfunit_comp_vector(&received, &expected, sizeof(float), "");
	hfunit_comp_float(received,expected, "");
	printf("expected: ");
	print_float(expected);
	printf("\t");
	printBits(4, &expected);
	printf("\nentrada: ");
	print_float(entrada);
	printf("\t");
	printBits(4, &entrada);
	printf("\nreceived: ");
	print_float(received);
	printf("\t");
	printBits(4, &received);
}
/*
//
void test3(){
	float expected = 1.0;
	float received = ceil(0x00000001);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printf("ex: %d, rc: %d\n", (int)expected, (int)received);
}

//
void test4(){
	float expected = 1.0;
	float received = ceil(0x00000001);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printf("ex: %d, rc: %d\n", (int)expected, (int)received);
}

//
void test5(){
	float expected = 1.0;
	float received = ceil(0x00000001);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printf("ex: %d, rc: %d\n", (int)expected, (int)received);
}

//
void test6(){
	float expected = 1.0;
	float received = ceil(0x00000001);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printf("ex: %d, rc: %d\n", (int)expected, (int)received);
}

//
void test7(){
	float expected = 1.0;
	float received = ceil(0x00000001);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printf("ex: %d, rc: %d\n", (int)expected, (int)received);
}*/