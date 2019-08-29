/*
  HF-RISC Unit Testing framework

  edit these macros to chage the behavior of HF-UNIT.
  See usage examples in the dir software/tests
*/

// =======================
// global counters
// =======================
extern int failed_tests;
extern int executed_tests;
extern int test_counter;


// =======================
// main definitions
// =======================

// floating point comparison precision
#define HFUNIT_PRECISION 0.00001

// define it to show message for every test
#define HFUNIT_VERBOSE

// define the output message format in case verbose mode is on
#ifdef HFUNIT_VERBOSE
	#define HFUNIT_MSG_FAIL(msg) printf("test %d) \'%s\' failed\n",test_counter, msg);
	#define HFUNIT_MSG_PASS(msg) printf("test %d) \'%s\' passed\n",test_counter, msg);
#else
	#define HFUNIT_MSG_FAIL(msg)
	#define HFUNIT_MSG_PASS(msg)
#endif

// =======================
// comparison functions
// =======================

// compare int vectors
int hfunit_comp_vector(int *v1,int *v2, int size, char* message){
	test_counter++;
	if (memcmp(v1,v2,size)!=0){
		failed_tests++;
		HFUNIT_MSG_FAIL(message)
	}else{
		HFUNIT_MSG_PASS(message)
	}
	executed_tests++;
}

// compare floats
int hfunit_comp_float(float f1,float f2, char *message){
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