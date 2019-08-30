#ifndef __SETTYPE_H
#define __SETTYPE_H

#include <hf-risc.h>
#include <libc.h>
#define NEW_SIZE 100

#ifdef TFIXED //===> FIXED POINT !!!!
#include "fixed.h"
typedef fixed_t typ_var;
#define SHOW(A)         fix_print(A)
#define mul(A,B)		fix_mul(A,B)
#define div(A,B)		fix_div(A,B)
#define val(A)          fix_val(A)
#define square_root(A)  fix_sqrt(A)
#define power(A,B)      fix_pow(A,B)
#define fabs(A)         fix_abs(A)
#define arc_sin(A)      fix_asin(A)
#define arc_tan2(A,B)   fix_atan2(A,B)
#define HALF_PI         fix_val(1.57079632679489661923)
#define PI			    fix_val(3.14159265358979323846)
#define cpsign(A,B)     fix_copysign(A,B)
#endif

#ifdef TDOUBLE //===> DOUBLE

typedef double typ_var;
#define SHOW(A)         print_double(A)
#define mul(A,B)		A*B
#define div(A,B)		A/B
#define val(A)          A
#define square_root(A)  sqrt(A)
#define power(A,B)      pow(A,B)
#define fabs(A)         abs(A)
#define arc_sin(A)      asin(A)
#define arc_tan2(A,B)   atan2(A,B)
#define HALF_PI         (1.57079632679489661923)
#define PI			    (3.14159265358979323846)
#define cpsign(A,B)     d_copysign(A,B)

#endif

#ifdef TFLOAT //===> FLOAT

typedef float typ_var;
#define SHOW(A)         print_float(A)
#define mul(A,B)		A*B
#define div(A,B)		A/B
#define val(A)          A
#define square_root(A)  sqrt(A)
#define power(A,B)      pow(A,B)
#define fabs(A)         abs(A)
#define arc_sin(A)      asin(A)
#define arc_tan2(A,B)   atan2(A,B)
#define HALF_PI         (1.57079632679489661923)
#define PI			    (3.14159265358979323846)
#define cpsign(A,B)     f_copysign(A,B)

#endif


#endif
