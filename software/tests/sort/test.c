#include <hf-risc.h>
#include <hf-unit.h>

extern int failed_tests;
extern int executed_tests;
int test_counter=0;

// test principal
void sort_test();

// funcao sendo testada
int sort(int v[], int e);

// testes individuais
void inorder_test();
void equal_test();

// funcoes comuns
int comp_vector(int *v1,int *v2, int size, char* message){
	test_counter++;
	if (memcmp(v1,v2,size)!=0){
		failed_tests++;
		HFUNIT_MSG_FAIL(message)
	}else{
		HFUNIT_MSG_PASS(message)
	}
	executed_tests++;
}

// test principal
void sort_test(){
	inorder_test();
	equal_test();
}

// descricao do teste xyz
void inorder_test(){
	int v[3] = {0, 1, 2};
	int expected[3] = {0, 2, 2};
	sort(v,3);
	comp_vector(v,expected,sizeof(int)*3, "in order vector");
}

// descricao do teste abc
void equal_test(){
	int v[3] = {1, 1, 1};
	int expected[3] = {1, 1, 1};
	sort(v,3);
	comp_vector(v,expected,sizeof(int)*3, "vector filled with the samr value");
}
