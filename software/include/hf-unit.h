/*
  HF-RISC Unit Testing framework

  edit these macros to chage the behavior of HF-UNIT.
  See usage examples in the dir software/tests
*/

#include <hf-risc.h>

// =======================
// global counters
// =======================
extern int failed_tests;
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
// util functions
// =======================
// debug function to print data in binary format
// source: https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
void printBits(size_t const size, void const * const ptr);

// =======================
// comparison functions
// =======================

// compare int/char/short vectors. do not use this for vector of float or double. it wont work !
int hfunit_comp_vector(void *v1,void *v2, int size, char* message);

// compare floats
int hfunit_comp_float(float f1,float f2, char *message);
