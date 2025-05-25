#include "../s21_unit_tests.h"

#define RESULT_COUNT 8
#define CALC_COUNT 2
#define INCOR_COUNT 2

START_TEST(test_determinant_result) {
  static const double values_a[RESULT_COUNT + CALC_COUNT][MAX_RANG] = {
      {1.234567, 2, -40, 3.9000999},
      {2, 3, 4, 5, 6, 7, 8, 9, 0},
      {1, 0, 0, 0, 1, 0, 0, 0, 1},
      {1, 2, 3, 1, 2, 6, 5, 4, 1},
      {1, 2, 3, 4, 5, 6, 7, 8, 9},
      {0, 3, 9, 0, 5, 0, 0, 1, -1},
      {1, 5, 6,  93, 3,  -34, 8, -1, 0, 0, -9, 3, 45, 3,  -3, -19, -40, -200,
       3, 9, 23, 45, 15, 22,  6, 7,  2, 8, 0,  0, -9, -7, 1,  1,   99,  12},
      {8},

      {4, 6, 8, 9},
      {6, 7, 8, 9, 10, 11, 12, 8, 9, 1},
  };

  static const int rang_a[RESULT_COUNT + CALC_COUNT][2] = {
      {2, 2}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {3, 3}, {6, 6}, {1, 1},

      {1, 4}, {5, 2},
  };

  static const double сheck_value[RESULT_COUNT] = {
      84.8149346332433, 30, 1, 18, 0, 0, 2096502228, 8,
  };

  static const int return_check[RESULT_COUNT + CALC_COUNT + INCOR_COUNT] = {
      0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 1, 1,
  };

  int rtrn = -1;
  int error_A = 0;

  if (_i == (RESULT_COUNT + CALC_COUNT)) {
    matrix_t *A = NULL;
    double res;

    rtrn = s21_determinant(A, &res);
    ck_assert_int_eq(rtrn, return_check[_i]);
  }

  if (_i == (RESULT_COUNT + CALC_COUNT + INCOR_COUNT - 1)) {
    double temp[] = {1, 2, 3, 4, 5, 6};
    matrix_t A;
    double *res = NULL;
    error_A = s21_create_matrix(2, 3, &A);
    if (!error_A) {
      s21_set_matrix(&A, temp);
      rtrn = s21_determinant(&A, res);
      ck_assert_int_eq(rtrn, return_check[_i]);
      s21_remove_matrix(&A);
    }
  }

  if (_i < (RESULT_COUNT + CALC_COUNT)) {
    matrix_t A;
    A.matrix = NULL;
    double res;

    error_A = s21_create_matrix(rang_a[_i][0], rang_a[_i][1], &A);
    if (!error_A) {
      s21_set_matrix(&A, values_a[_i]);

      rtrn = s21_determinant(&A, &res);

      ck_assert_int_eq(rtrn, return_check[_i]);

      if (!rtrn) {
        ck_assert_double_eq_tol(сheck_value[_i], res, EPS);
      }
      s21_remove_matrix(&A);
    }
  }
}
END_TEST

Suite *test_determinant_suite(void) {
  Suite *s;
  TCase *tc_result;

  s = suite_create(" + determinant");
  tc_result = tcase_create("\n==determinant== -result-\n");

  tcase_set_timeout(tc_result, TEST_TIMEOUT);
  tcase_add_loop_test(tc_result, test_determinant_result, 0,
                      RESULT_COUNT + CALC_COUNT + INCOR_COUNT);
  suite_add_tcase(s, tc_result);
  return s;
}
