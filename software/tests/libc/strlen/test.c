//Eduardo Porto e Johannes Portz
//T1 Teste e Confiabilidade de Sistemas
#include <hf-risc.h>
#include <hf-unit.h>

// function under test
int32_t strlen(const int8_t *s);

// list of individual tests
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();

// main test
void hfunit_run_tests_strlen(){
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
}

// teste com menor valor de string - 0
void test1(){
	char string[] = "";
	int expected = 0;
	int received = strlen(string);
	printf("\t%d ----- rc: %d\n", expected, received);
	hfunit_comp_vector(&expected, &received, sizeof(int), "teste 1");
}

// passando um char apenas
void test2(){
	char string = 'a';
	int expected = 1;
	int received = strlen(&string);
	printf("\t%d ----- rc: %d\n", expected, received);
	hfunit_comp_vector(&expected, &received, sizeof(int), "teste 2");
}

//passando desta vez um pointer para inteiro de 32 bits e não char
void test3(){
	int integer[2] = {1, 2};
	int expected = 2;
	int received = strlen(integer);
	printf("\t%d ----- rc: %d\n", expected, received);
	hfunit_comp_vector(&expected, &received, sizeof(int), "teste 3");
}

//passando um inteiro de 32 bits e não um char de 8 bits
void test4(){
	int integer = 2147483647;
	int expected = 1; //por ser um valor, se for contar por bytes seria 4
	int received = strlen(&integer);
	printf("\t%d ----- rc: %d\n", expected, received);
	hfunit_comp_vector(&expected, &received, sizeof(int), "teste 4");
}

//passando apenas um inteiro
void test5(){
	int integer = 0;
	int expected = 1; //por ser um valor, se for contar por bytes seria 4
	int received = strlen(&integer);
	printf("\t%d ----- rc: %d\n", expected, received);
	hfunit_comp_vector(&expected, &received, sizeof(int), "teste 5");
}

//teste extra, passando string de 10 digitos
void test6(){
	char string[] = "0123456789";
	int expected = 10;
	int received = strlen(string);
	printf("\t%d ----- rc: %d\n", expected, received);
	hfunit_comp_vector(&expected, &received, sizeof(int), "teste 6");
}

//teste extra, passando string de tamanho 10 mas com valor em apenas 4 bytes
void test7(){
	char string[10] = "0123"; 
	int expected = 4;
	int received = strlen(string);
	printf("\t%d ----- rc: %d\n", expected, received);
	hfunit_comp_vector(&expected, &received, sizeof(int), "teste 7");
}