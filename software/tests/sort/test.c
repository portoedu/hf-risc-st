#include <hf-risc.h>

extern int failed_tests;
extern int executed_tests;

// test principal
void sort_test();

// funcao sendo testada
int sort(int v[], int e);

// testes individuais
void inorder_test();
void equal_test();

// funcoes comuns
int comp_vector(int *v1,int *v2, int size){
	if (memcmp(v1,v2,size)!=0)
		failed_tests++;
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
	comp_vector(v,expected,sizeof(int)*3);
}

// descricao do teste abc
void equal_test(){
	int v[3] = {1, 1, 1};
	int expected[3] = {1, 1, 1};
	sort(v,3);
	comp_vector(v,expected,sizeof(int)*3);
}
