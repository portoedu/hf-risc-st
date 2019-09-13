//Eduardo Porto e Johannes Portz
//T1 Teste e Confiabilidade de Sistemas

/*
Tabela de equivalencia
			validas		invalidas
entradas	char[]		não char[]				
			Aceito		não é um char[]
*/

/* Tabela de testes
	Entrada   	  Saída
	   ""    	    0
      "a"    	    1
      int[]  	 não é char[]
	  int		 não é char[]
 char[]"0123..."    10
 char[10]="0123"    4

*/
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

/* teste com string vazia, para retornar o menor valor possível
   de retorno da função.
*/
void test1(){
	char string[] = "";
	int expected = 0;
	int received = strlen(string);
	hfunit_comp_vector(&expected, &received, sizeof(int), "teste 1");
	printf("\t%d ----- rc: %d\n", expected, received);
}

/* teste com um char, sem NULL no fim
   retorno correto seria 1, mas o comportamento
   esperado não é esse.
*/
void test2(){
	char string = "a";
	int expected = 1;
	int received = strlen(&string);
	hfunit_comp_vector(&expected, &received, sizeof(int), "teste 2");
	printf("\t%d ----- rc: %d\n", expected, received);
}

/*teste com um ponteio para um vetor de inteiros,
  totalizando 64 bits. 
*/
void test3(){
	int integer[2] = {-1,2};
	int expected = 8;
	int received = strlen(integer);
	hfunit_comp_vector(&expected, &received, sizeof(int), "teste 3");
	printf("\t%d ----- rc: %d\n", expected, received);
}

//passando um inteiro de 32 bits com todos os bits em 1
 
void test4(){
	int integer = 2147483647;
	int expected = 4; 
	int received = strlen(&integer);
	hfunit_comp_vector(&expected, &received, sizeof(int), "teste 4");
	printf("\t%d ----- rc: %d\n", expected, received);
}

//passando um inteiro de 32 bits com todos os bits em 0
void test5(){
	int integer = 0;
	int expected = 1;
	int received = strlen(&integer);
	hfunit_comp_vector(&expected, &received, sizeof(int), "teste 5");
	printf("\t%d ----- rc: %d\n", expected, received);
}

//teste extra, passando string com 10 caracteres numéricos
void test6(){
	char string[] = "0123456789";
	int expected = 10;
	int received = strlen(string);
	hfunit_comp_vector(&expected, &received, sizeof(int), "teste 6");
	printf("\t%d ----- rc: %d\n", expected, received);
}

//teste extra, passando string de tamanho 10 inicializada em apenas 4 posições
void test7(){
	char string[10] = "0123"; 
	int expected = 4;
	int received = strlen(string);
	hfunit_comp_vector(&expected, &received, sizeof(int), "teste 7");
	printf("\t%d ----- rc: %d\n", expected, received);
}
