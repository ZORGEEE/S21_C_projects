#ifndef S21_UNIT_TESTS
#define S21_UNIT_TESTS

#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"
#define TEST_TIMEOUT 0.1
#define EPS 1e-6
#define MAX_RANG 50

Suite *test_create_suite(void);
Suite *test_remove_suite(void);

Suite *test_eq_suite(void);
Suite *test_sub_suite(void);
Suite *test_sum_suite(void);

Suite *test_mult_matrix_suite(void);
Suite *test_mult_number_suite(void);

Suite *test_transpose_suite(void);
Suite *test_calc_complements_suite(void);
Suite *test_determinant_suite(void);
Suite *test_inverse_suite(void);

void s21_set_matrix(matrix_t *A, const double *src);
void s21_print_matrix(matrix_t A);

#endif
