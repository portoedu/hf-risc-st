/*
This matrix lib can work with 3 different types: fixed, float, and double.
just change the variable MATRIX_TYPE in the makefile
*/

/*
Tabela de equivalencia
			validas		invalidas
entradas	Matriz		não matriz
tamanho		>= 0 		< 0				
			Aceito		não aceito
*/

/* Tabela de testes
	Entrada   	        Saída
     4x4                   4
     1x1                   1
     0x0                   0
     10x2                  2
*/

#include <mat_type.h> // this include define the type of the matrix
#include <matrix.h>   // the functions under test are defined here
#include <hf-risc.h>
#include <hf-unit.h>


// list of individual tests
//void sqrt1_test();
//void sqrt4_test();
void teste1();
void teste2();
void teste3();
void teste4();


// main test
void hfunit_run_tests(){
	teste1();
	teste2();
	teste3();
	teste4();
}

//Teste setando uma matriz 4x4 e pegando o número de colunas
void teste1() {

struct Matrix M1;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};

M1 = set_values(4, 4, val1);

//----------------------------FUNCTIONS TESTS-----------------------------------

printf("Matrix 1 is:\n");
print_matrix(M1);

int l1 = get_column(M1);
printf("Colunas: %d\n", l1);
int expected = 4;
hfunit_comp_vector(&expected, &l1, sizeof(int), "teste");
}

//Teste setando uma matriz 1x1, valor pequeno, e pegando o número de colunas
void teste2() {

struct Matrix M1;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};

M1 = set_values(1, 1, val1);

//----------------------------FUNCTIONS TESTS-----------------------------------

printf("Matrix 1 is:\n");
print_matrix(M1);

int l1 = get_column(M1);
printf("Colunas: %d\n", l1);
int expected = 1;
hfunit_comp_vector(&expected, &l1, sizeof(int), "teste");
}

//Teste com o menos valor possível de tamanho de matriz 0x0, e pegando o número de colunas
void teste3() {

struct Matrix M1;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
M1 = set_values(0, 0, val1);
//----------------------------FUNCTIONS TESTS-----------------------------------

printf("Matrix 1 is:\n");
print_matrix(M1);

int l1 = get_column(M1);
printf("Colunas: %d\n", l1);
int expected = 0;
hfunit_comp_vector(&expected, &l1, sizeof(int), "teste");
}

//Teste extra onde o número de colunas é diferente do número de linhas
void teste4() {

struct Matrix M1;
typ_var val1[20] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16), val(17), val(18), val(19), val(20)};
M1 = set_values(10, 2, val1);
//----------------------------FUNCTIONS TESTS-----------------------------------

printf("Matrix 1 is:\n");
print_matrix(M1);

int l1 = get_column(M1);
printf("Colunas: %d\n", l1);
int expected = 2;
hfunit_comp_vector(&expected, &l1, sizeof(int), "teste");
}
