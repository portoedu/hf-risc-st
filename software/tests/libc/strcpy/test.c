//Eduardo Porto e Johannes Portz
//T1 Teste e Confiabilidade de Sistemas

/*
Tabela de equivalencia
			validas		invalidas
entradas	char[]		não char[]				
			Aceito		não é um char[]

Dentro das funções se o parametro passado 
não está no intervalo -pi<0<pi, o valor 
2pi eh acrescentado ou diminuido dele
*/

/* Tabela de testes
	Entrada   	        Saída
    char[7] ->[7]      copiado
    ".." ->  [7]       copiado
    char[7] -> [5]     copiado (invade)
    char -> [1]        copiado
    int -> char[]      entrada n é char[]
    char[2]-> [5]      copiado
    char -> char       copiado
*/
#include <hf-risc.h>
#include <hf-unit.h>

// function under test
int8_t *strcpy(int8_t *dst, const int8_t *src);

// list of individual tests
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();

// main test
void hfunit_run_tests_strcpy(){
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
}

// teste simples copiando a string "teste 1" a partir
// de uma variável para uma variavel destino do tamanho exato
void test1(){
	char srcString[] = "teste 1";
	char dstString[7];
	strcpy(dstString, srcString);
	hfunit_comp_vector(dstString, srcString, 7, "");
}

// teste extra semelhante ao anterior, passando uma
// string diretamente para a funcao
void test2(){
	char dstString[7];
	strcpy(dstString, "teste 2");
	hfunit_comp_vector(dstString, "teste 2", 7, "");
}

// teste passando uma string de tamanho 7 para uma
// variavel de tamanho 5
void test3(){
	char srcString[] = "teste 1";
	char dstString[5];
	strcpy(dstString, srcString);
	hfunit_comp_vector(dstString, srcString, 7, "");
}

// testando passando um char sem ser vetor, passando 
// o endereco desse char para a funcao
void test4(){
	char srcString = ' ';
	char dstString[1];
	strcpy(dstString, &srcString);
	hfunit_comp_vector(dstString, &srcString, 1, "");
}

// teste passando o endereco de um inteiro para
// um array de char de tamanho 4 para testar passando diferentes tipos de variáveis
void test5(){
	int src = 1234;
	char dstString[4];
	strcpy(dstString,&src);
	hfunit_comp_vector(dstString, &src, 4, "");
}

//teste passado uma string menor para um destino de tamanho maior
void test6(){
	char srcString[2] = "ab";
	char dstString[5];
	strcpy(dstString, srcString);
	hfunit_comp_vector(dstString, srcString, 2, "");
}

//teste passado um char apenas ( não inicializado ) para um destino de mesmo tamanho - menor cópia possivel
void test7(){
	char srcString;
	char dstString = 'a';
	strcpy(&dstString, &srcString);
	hfunit_comp_vector(&dstString, &srcString, 1, "");
}
