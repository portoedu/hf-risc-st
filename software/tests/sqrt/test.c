#include <hf-risc.h>
#include <hf-unit.h>

extern int failed_tests;
extern int executed_tests;
int test_counter=0;

// test principal 
void sqrt_test();

// funcao sendo testada
float sqrt(float arg);

// testes individuais
void sqrt1_test();
void sqrt4_test();

// funcoes comuns
int comp_float(float f1,float f2, char *message){
	test_counter++;
	if (!(((f1 - HFUNIT_PRECISION) < f2) && ((f1 + HFUNIT_PRECISION) > f2)))
	{
		failed_tests++;
		HFUNIT_MSG_FAIL(message)
	}else{
		HFUNIT_MSG_PASS(message)
	}
	executed_tests++;
}

// test principal
void sqrt_test(){
	sqrt1_test();
	sqrt4_test();
}

// descricao do teste xyz
void sqrt1_test(){
	float v = sqrt(1.0);
	float expected = 1.0;
	comp_float(v,expected, "sqrt(1.0)");
}

// descricao do teste abc
void sqrt4_test(){
	float v = sqrt(4.0);
	float expected = 2.0;
	comp_float(v,expected, "sqrt(4.0)");
}
