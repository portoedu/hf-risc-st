#include <hf-risc.h>

// global vars to count the # of executed tests 
int executed_tests=0;
int failed_tests=0;

//define prototipo dos testes
void sqrt_test();


//funcao que vai fazer o teste
void main_test(int argc, char** argv){

	
	printf("=====================\n");
	sqrt_test();
	printf("%d tests executed - %d tests failed\n", executed_tests, failed_tests);
	printf("=====================\n");
	if (failed_tests != 0)
		printf("TEST FAILED !!!\n");
	else
		printf("TEST SUCCEEDED !!!\n");
}