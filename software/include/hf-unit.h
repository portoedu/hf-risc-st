/*
  HF-RISC Unit Testing framework

  edit these macros to chage the behavior of HF-UNIT.
  See usage examples in the dir software/tests
*/

// floating point comparison precision
#define HFUNIT_PRECISION 0.00001

// define it to show message for every test
//#define HFUNIT_VERBOSE

// define the output message format in case verbose mode is on
#ifdef HFUNIT_VERBOSE
	#define HFUNIT_MSG_FAIL(msg) printf("test %d) \'%s\' failed\n",test_counter, msg);
	#define HFUNIT_MSG_PASS(msg) printf("test %d) \'%s\' passed\n",test_counter, msg);
#else
	#define HFUNIT_MSG_FAIL(msg)
	#define HFUNIT_MSG_PASS(msg)
#endif