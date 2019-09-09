/*
This matrix lib can work with 3 different types: fixed, float, and double.
just change the variable MATRIX_TYPE in the makefile
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

// place here a nice description for each test
// eu peguei um exemplao só p vcs verem como usar as funcoes
// mas vcs vao ter q separar bem os teste. nao pode fazer assim !!!
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

void teste4() {

struct Matrix M1;

M1 = set_values(10, 2, val(0));
//----------------------------FUNCTIONS TESTS-----------------------------------

printf("Matrix 1 is:\n");
print_matrix(M1);

int l1 = get_line(M1);
printf("Linhas: %d\n", l1);

}