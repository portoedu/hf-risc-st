#include <hf-risc.h>

//define prototipo das funcoes que vao ser testadas
void swap(int v[], int i, int j);


//funcao que vai fazer o teste
void main_test(int argc, char** argv){

	int v[3] = {0, 1, 2};
	
	printf("antes");
	printf("[0]=%d, [1]=%d, [2]=%d\n", v[0], v[1], v[2]);
	
	swap(v, 0, 1);
	
	printf("depois");
	printf("[0]=%d, [1]=%d, [2]=%d\n", v[0], v[1], v[2]);
}