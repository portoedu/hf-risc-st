//Eduardo Porto e Johannes Portz
//T1 Teste e Confiabilidade de Sistemas
#include <hf-risc.h>
#include <hf-unit.h>
/* Tabela de Limites
	Entrada   	        Saída
     0x00000001            0
     1                     1
     -0,9                 -1
     0x80000001           -1
     0x3FFFFFFF            1
	 0xBFFFFFFF           -2
     0,9998                0
     0,002                 0
*/

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

// Teste com uma entrada float com valor bem pequeno
void test1(){
	float expected = 0.0;
	union dat entrada;
	entrada.l = 0x00000001;
	float received = floor(entrada.f);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printBits(4, &entrada);
	printf("\n\n");
}

// Teste com uma entrada com valor já em inteiro
void test2(){
	float expected = 1.0;
	float entrada = 1.0;
	float received = floor(entrada);
	hfunit_comp_float(received,expected, "");
	printBits(4, &entrada);
	printf("\n\n");
}

// Teste com entrada com valor negativo, note que para passar no teste o valor esperado teve de ser -0.0!
void test3(){
	float expected = -1.0;
	float entrada = -0.9;
	float received = floor(entrada);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printBits(4, &entrada);
	printf("\n\n");
}

//Teste com valor negativo extremamente próximo à 0.0, -1.40129846432481707092372958329E-45
void test4(){
	float expected = -1.0;
	union dat entrada;
	entrada.l = 0x80000001;
	float received = floor(entrada.f);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printBits(4, &entrada);
	printf("\n\n");
}

//teste com valor bem próximo à 2, 1.99999988079071044921875
void test5(){
	float expected = 1.0;
	union dat entrada;
	entrada.l = 0x3FFFFFFF;
	float received = floor(entrada.f);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printBits(4, &entrada);
	printf("\n\n");
}

//entrada negativa muito próxima à -2.0, -1.99999988079071044921875E0
void test6(){
	float expected = -2.0;
	union dat entrada;
	entrada.l = 0xBFFFFFFF;
	float received = floor(entrada.f);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printBits(4, &entrada);
	printf("\n\n");
}

//teste extra, com entrada próxima à 1.0 porém entrando valor em float e não em hexadecimal
void test7(){
	float expected = 0.0;
	float entrada = 0.999998999899898;
	float received = floor(entrada);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printBits(4, &entrada);
	printf("\n\n");
}

///teste extra, com entrada próxima à 0.0 porém entrando valor em float e não em hexadecimal
void test8(){
	float expected = 0.0;
	float entrada = 0.000000002;
	float received = floor(entrada);
	hfunit_comp_vector(&received, &expected, sizeof(float), "");
	printBits(4, &entrada);
	printf("\n\n");
}
