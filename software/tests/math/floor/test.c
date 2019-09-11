//Eduardo Porto e Johannes Portz
//T1 Teste e Confiabilidade de Sistemas
#include <hf-risc.h>
#include <hf-unit.h>

union dat { 
	float f;
	int l;
};

// function under test
float floor(float d);

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
void hfunit_run_tests_floor(){
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
}

// entrada com valor pequeno de float
void test1(){
	float expected = 0.0;
	union dat entrada;
	entrada.l = 0x00000001;
	float received = floor(entrada.f);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printBits(4, &entrada);
	printf("\n\n");
}

// entrada com valor já inteiro
void test2(){
	float expected = 1.0;
	float entrada = 1.0;
	float received = floor(entrada);
	hfunit_comp_float(received,expected, "");
	printBits(4, &entrada);
	printf("\n\n");
}

// entrada com valor negativo!
void test3(){
	float expected = -1.0;
	float entrada = -0.9;
	float received = floor(entrada);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printBits(4, &entrada);
	printf("\n\n");
}

//entrada com valor negativo bem próximo à 0.0
void test4(){
	float expected = -1.0;
	union dat entrada;
	entrada.l = 0x80000001;
	float received = floor(entrada.f);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printBits(4, &entrada);
	printf("\n\n");
}

//teste com valor bem próximo à 2
void test5(){
	float expected = 1.0;
	union dat entrada;
	entrada.l = 0x3FFFFFFF;
	float received = floor(entrada.f);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printBits(4, &entrada);
	printf("\n\n");
}

//entrada negativa muito próxima à -2.0
void test6(){
	float expected = -2.0;
	union dat entrada;
	entrada.l = 0xBFFFFFFF;
	float received = floor(entrada.f);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printBits(4, &entrada);
	printf("\n\n");
}

//teste com entrada próxima à 1.0 porém entrando valor em float e não em hexadecimal
void test7(){
	float expected = 0.0;
	float entrada = 0.999998999899898;
	float received = floor(entrada);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printBits(4, &entrada);
	printf("\n\n");
}

//teste com entrada próxima à 0.0 porém entrando valor em float e não em hexadecimal
void test8(){
	float expected = 0.0;
	float entrada = 0.000000002;
	float received = floor(entrada);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printBits(4, &entrada);
	printf("\n\n");
}