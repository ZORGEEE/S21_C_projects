#ifndef C5_S21_DECIMAL_0_TESTS_H
#define C5_S21_DECIMAL_0_TESTS_H

#include <check.h>

#include "../s21_decimal.h"

#define OK 0
#define TRUE 1
#define SUCCESS 0
#define FALSE 0
#define INF 1
#define N_INF 2
#define N_NAN 3

int test_arithmetic();
int test_comparison();
int test_conversion();
int test_other();

#endif  // C5_S21_DECIMAL_0_TESTS_H
