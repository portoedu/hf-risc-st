/*
  HF-RISC Unit Testing framework

  edit these macros to chage the behavior of HF-UNIT.
  See usage examples in the dir software/tests
*/
#include<hf-unit.h>

// =======================
// comparison functions
// =======================

// compare int/char/short vectors. do not use this for vector of float or double. it wont work !
int hfunit_comp_vector(void *v1,void *v2, int size, char* message){
	test_counter++;
	if (memcmp(v1,v2,size)!=0){
		failed_tests++;
		HFUNIT_MSG_FAIL(message)
		return 1;
	}else{
		HFUNIT_MSG_PASS(message)
		return 0;
	}
}

// compare floats
int hfunit_comp_float(float f1,float f2, char *message){
	test_counter++;
	if (!(((f1 - HFUNIT_PRECISION) < f2) && ((f1 + HFUNIT_PRECISION) > f2)))
	{
		failed_tests++;
		HFUNIT_MSG_FAIL(message)
		return 1;
	}else{
		HFUNIT_MSG_PASS(message)
		return 0;
	}
}