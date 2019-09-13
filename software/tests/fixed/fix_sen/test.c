//Eduardo Porto e Johannes Portz
//T1 Teste e Confiabilidade de Sistemas

/* Tabela de Limites
	Entrada    Saída
	-pi          0
     pi          0
     0           0
    0,00001      0
     pi/2        1
     pi/4      0,707
     2pi         0
     2         0,909
     3pi/2      -1
*/


#include <hf-risc.h>
#include <hf-unit.h>
#include <fixed.h>

// function under test
fixed_t fix_sin(fixed_t rad);

// list of individual tests
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();

// main test
void hfunit_run_tests_fix_sin(){
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
}

//Teste com o valor de -PI, que é um dos valores de entrada que são testados
void test1(){
	fixed_t expected = fix_val(0);
	fixed_t received = fix_sin(-FIX_PI);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n", fix_int(expected), fix_int(received));
	printBits(8, &expected);
	printBits(8, &received);
	printf("\n\n");
}

//Teste semelhante ao anterior, dessa vez com o valor positivo, já que é outro valor limite
void test2(){
	fixed_t expected = fix_val(0);
	fixed_t received = fix_sin(FIX_PI);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n", fix_int(expected), fix_int(received));
	printBits(8, &expected);
	printBits(8, &received);
	printf("\n\n");
}

//Teste com o valor 0 pois é a metade entre os valores utilizados na função, -pi a pi
void test3(){
	fixed_t expected = fix_val(0);
	fixed_t received = fix_sin(0);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n", fix_int(expected), fix_int(received));
	printBits(8, &expected);
	printBits(8, &received);
	printf("\n\n");
}

//Teste com um valor bem pŕoximo de 0, para testar se há diferença.
void test4(){
	fixed_t expected = fix_val(0);
	fixed_t received = fix_sin(0.0000001);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n", fix_int(expected), fix_int(received));
	printBits(8, &expected);
	printBits(8, &received);
	printf("\n\n");
}

//
//Teste com valor que se encontra na metade entre 0 e pi, que são os valores positivos aceitos
void test5(){
	fixed_t expected = fix_val(1);
	fixed_t received = fix_sin(FIX_HALF_PI);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n", fix_int(expected), fix_int(received));
	printBits(8, &expected);
	printBits(8, &received);
	printf("\n\n");
}

//Teste extra, com valor de 1/4 de pi para vermos a precisão do resultado, no resultado esperado a precisão é de 3 casas depois da virgula
void test6(){
	fixed_t expected = fix_val(0.707);
	fixed_t received = fix_sin(FIX_FOURTH_PI);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n", fix_int(expected), fix_int(received));
	printBits(8, &expected);
	printBits(8, &received);
	printf("\n\n");
}

//Teste com o valor maior que o utilziado na função, sendo dentro dela diminuido 2pi
void test7(){
	fixed_t expected = fix_val(0);
	fixed_t received = fix_sin(FIX_TWO_PI);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n", fix_int(expected), fix_int(received));
	printBits(8, &expected);
	printBits(8, &received);
	printf("\n\n");
}

//Teste extra com um valor diferente de algum referencial de pi
void test8(){
	fixed_t expected = fix_val(0.909);
	fixed_t received = fix_sin(fix_val(2));
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n", fix_int(expected), fix_int(received));
	printBits(8, &expected);
	printBits(8, &received);
	printf("\n\n");
}

//Teste extra apenas para observar o resultado negativo desta função
void test9(){
	fixed_t expected = fix_val(-1);
	fixed_t received = fix_sin(3*FIX_HALF_PI);
	hfunit_comp_vector(&received, &expected, 8, "");
	printf("ex: %d - rc: %d \n", fix_int(expected), fix_int(received));
	printBits(8, &expected);
	printBits(8, &received);
	printf("\n\n");
}
