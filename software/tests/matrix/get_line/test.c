/*
This matrix lib can work with 3 different types: fixed, float, and double.
just change the variable MATRIX_TYPE in the makefile
*/
/* Tabela de Limites
	Entrada   	        Saída
     4x4                   4
     1x1                   1
     0x0                   0
     10x2                  10
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

//Teste inicial setando uma matriz 4x4 e pegando o número de linhas dela
void teste1() {

struct Matrix M1;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};

M1 = set_values(4, 4, val1);

//----------------------------FUNCTIONS TESTS-----------------------------------

printf("Matrix 1 is:\n");
print_matrix(M1);

int l1 = get_line(M1);
printf("Linhas: %d\n", l1);

}

//Teste com uma matriz 1x1, matriz pequena, e pegando o número de linhas dela
void teste2() {

struct Matrix M1;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};

M1 = set_values(1, 1, val1);

//----------------------------FUNCTIONS TESTS-----------------------------------

printf("Matrix 1 is:\n");
print_matrix(M1);

int l1 = get_line(M1);
printf("Linhas: %d\n", l1);

}

//Teste com a menor matriz possível, 0x0, e pegando o número de linahs dela
void teste3() {

struct Matrix M1;

typ_var val1[16] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16)};
M1 = set_values(0, 0, val1);
//----------------------------FUNCTIONS TESTS-----------------------------------

printf("Matrix 1 is:\n");
print_matrix(M1);

int l1 = get_line(M1);
printf("Linhas: %d\n", l1);

}

//Teste pegando uma matriz com número de linhas diferente do número de colunas e pegando o número de linhas dela
void teste4() {

typ_var val1[20] = {val(1),val(2),val(3),val(4),val(5),val(6),val(7),val(8),val(9),val(10),val(11),val(12),val(13),val(14),val(15),val(16), val(17), val(18), val(19), val(20)};
struct Matrix M1;

M1 = set_values(10, 2, val1);
//----------------------------FUNCTIONS TESTS-----------------------------------

printf("Matrix 1 is:\n");
print_matrix(M1);

int l1 = get_line(M1);
printf("Linhas: %d\n", l1);

}
