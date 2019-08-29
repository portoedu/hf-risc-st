#include <hf-risc.h>

// global vars to count the # of executed tests. do not delete them !
int executed_tests=0;
int failed_tests=0;
int test_counter=0;

//define the main test prototype
void hfunit_run_tests();


//funcao que vai fazer o teste
int main_test(int argc, char** argv){

	printf("=====================\n");
	hfunit_run_tests();
	printf("=====================\n");
	printf("%d tests executed - %d tests failed\n", executed_tests, failed_tests);
	printf("=====================\n");
	if (failed_tests != 0){
		printf("TEST FAILED !!!\n");
		return 1;
	}
	else{
		printf("TEST SUCCEEDED !!!\n");
		return 0;
	}
}