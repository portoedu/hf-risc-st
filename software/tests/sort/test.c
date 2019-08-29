#include <hf-risc.h>
#include <hf-unit.h>

// function under test
int sort(int v[], int e);

// list of individual tests
void inorder_test();
void equal_test();

// main test
void hfunit_run_tests(){
	inorder_test();
	equal_test();
}

// place here a nice description for each test
void inorder_test(){
	int v[3] = {0, 1, 2};
	int expected[3] = {0, 2, 2};
	sort(v,3);
	hfunit_comp_vector(v,expected,sizeof(int)*3, "in order vector");
}

// place here a nice description for each test
void equal_test(){
	int v[3] = {1, 1, 1};
	int expected[3] = {1, 1, 1};
	sort(v,3);
	hfunit_comp_vector(v,expected,sizeof(int)*3, "vector filled with the samr value");
}
