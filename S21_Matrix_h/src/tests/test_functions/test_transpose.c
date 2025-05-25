#include "../s21_unit_tests.h"

#define RESULT_COUNT 3
#define CALC_COUNT 0
#define INCOR_COUNT 2

START_TEST(test_transpose_result) {
  static const double values_a[RESULT_COUNT + CALC_COUNT][MAX_RANG] = {
      {1, 2, -4, 3, 6, -0.00000001, 74, 0, -9, 8},
      {2, 3, 4, 5, 6, 7, 8, 9, 0},
      {8},
  };

  static const int rang_a[RESULT_COUNT + CALC_COUNT][2] = {
      {2, 5},
      {3, 3},
      {1, 1},
  };

  static const double values_c[RESULT_COUNT][MAX_RANG] = {
      {1, -0.00000001, 2, 74, -4, 0, 3, -9, 6, 8},
      {2, 5, 8, 3, 6, 9, 4, 7, 0},
      {8},
  };

  static const int rang_c[RESULT_COUNT][2] = {{5, 2}, {3, 3}, {1, 1}};

  static const int return_check[RESULT_COUNT + CALC_COUNT + INCOR_COUNT] = {
      0, 0, 0, 1, 1,
  };

  int rtrn = -1;
  int error_A = 0;
  int error_C = 0;

  if (_i == (RESULT_COUNT + CALC_COUNT)) {
    matrix_t *A = NULL;
    matrix_t res;

    rtrn = s21_transpose(A, &res);
    ck_assert_int_eq(rtrn, return_check[_i]);
  }

  if (_i == (RESULT_COUNT + CALC_COUNT + INCOR_COUNT - 1)) {
    double temp[] = {1, 2, 3, 4, 5, 6};
    matrix_t A;
    matrix_t *res = NULL;
    error_A = s21_create_matrix(2, 3, &A);
    if (!error_A) {
      s21_set_matrix(&A, temp);
      rtrn = s21_transpose(&A, res);
      ck_assert_int_eq(rtrn, return_check[_i]);
      s21_remove_matrix(&A);
    }
  }

  if (_i < (RESULT_COUNT + CALC_COUNT)) {
    matrix_t A;
    A.matrix = NULL;
    matrix_t C;
    C.matrix = NULL;
    matrix_t res;

    error_A = s21_create_matrix(rang_a[_i][0], rang_a[_i][1], &A);
    if (!error_A) s21_set_matrix(&A, values_a[_i]);

    if (_i < RESULT_COUNT) {
      error_C = s21_create_matrix(rang_c[_i][0], rang_c[_i][1], &C);
      if (!error_C) s21_set_matrix(&C, values_c[_i]);
    }

    rtrn = s21_transpose(&A, &res);
    ck_assert_int_eq(rtrn, return_check[_i]);

    if (!error_C && !rtrn) {
      rtrn = calc_is_equal_size(&res, &C);
      ck_assert_msg(!rtrn, "Not equal size in test: %d", _i);

      if (!rtrn) {
        for (int i = 0; i < res.rows; i++) {
          for (int j = 0; j < res.columns; j++) {
            ck_assert_double_eq_tol(C.matrix[i][j], res.matrix[i][j], EPS);
          }
        }
      }
    }

    if (!error_A) s21_remove_matrix(&A);
    if (!error_C && _i < RESULT_COUNT) s21_remove_matrix(&C);
    if (!rtrn) s21_remove_matrix(&res);
  }
}
END_TEST

Suite *test_transpose_suite(void) {
  Suite *s;
  TCase *tc_result;

  s = suite_create(" + transpose");
  tc_result = tcase_create("\n==transpose== -result-\n");

  tcase_set_timeout(tc_result, TEST_TIMEOUT);
  tcase_add_loop_test(tc_result, test_transpose_result, 0,
                      RESULT_COUNT + CALC_COUNT + INCOR_COUNT);
  suite_add_tcase(s, tc_result);
  return s;
}
