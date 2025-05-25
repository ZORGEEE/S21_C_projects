#include "../s21_unit_tests.h"

#define RESULT_COUNT 4
#define CALC_COUNT 2
#define INCOR_COUNT 3

START_TEST(test_sum_result) {
  static const double values_a[RESULT_COUNT + CALC_COUNT][MAX_RANG] = {
      {2, 3, 4, 5, 6, 7, 8, 9, 0},
      {3.49999, 5.023424, 7.3563, 0.00005399, 564.34, 34.2345246, 0.5466463,
       34.5435, -9.3424, -0.00000001},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {8},

      {4, 6, 8, 9},
      {6, 7, 8, 9, 10, 11, 12, 8, 9},
  };

  static const int rang_a[RESULT_COUNT + CALC_COUNT][2] = {
      {3, 3}, {5, 2}, {3, 3}, {1, 1},

      {1, 4}, {3, 3},
  };

  static const double values_b[RESULT_COUNT + CALC_COUNT][MAX_RANG] = {
      {1, 0.001, 43.432, 5.98, 2.665, -0.0004, 1, 5, 9.9999999},
      {2.342, 8.0908, -34.65, -0.000259, 6.453, 0, 0, 0, -1, 1},
      {7, 456456, 45, 35645, 23524, 565, 0.003, 6, -9},
      {10.0000001},

      {9, 0, 0, 1, 4, 7},
      {1, 2, 3, 6},
  };

  static const int rang_b[RESULT_COUNT + CALC_COUNT][2] = {
      {3, 3}, {5, 2}, {3, 3}, {1, 1},

      {2, 3}, {2, 2},
  };

  static const double values_c[RESULT_COUNT][MAX_RANG] = {
      {3, 3.001, 47.432, 10.98, 8.665, 6.9996, 9, 14, 9.9999999},
      {5.84199, 13.114224, -27.2937, -0.00020501, 570.793, 34.2345246,
       0.5466463, 34.5435, -10.3424, 0.99999999},
      {7, 456456, 45, 35645, 23524, 565, 0.003, 6, -9},
      {18.0000001},
  };

  static const int rang_c[RESULT_COUNT][2] = {{3, 3}, {5, 2}, {3, 3}, {1, 1}};

  static const int return_check[RESULT_COUNT + CALC_COUNT + INCOR_COUNT] = {
      0, 0, 0, 0, 2, 2, 1, 1, 1};

  int rtrn = -1;
  int error_A = 0;
  int error_B = 0;
  int error_C = 0;

  if (_i == (RESULT_COUNT + CALC_COUNT)) {
    double temp[] = {1, 2, 3, 4, 5, 6};
    matrix_t A;
    matrix_t *B;
    matrix_t res;
    error_A = s21_create_matrix(2, 3, &A);
    if (!error_A) {
      s21_set_matrix(&A, temp);
      B = NULL;
      rtrn = s21_sum_matrix(&A, B, &res);
      ck_assert_int_eq(rtrn, return_check[_i]);
      s21_remove_matrix(&A);
    }
  }

  if (_i == (RESULT_COUNT + CALC_COUNT + 1)) {
    double temp[] = {1, 2, 3, 4, 5, 6};
    matrix_t *A;
    matrix_t B;
    matrix_t res;
    error_B = s21_create_matrix(2, 3, &B);
    if (!error_B) {
      s21_set_matrix(&B, temp);
      A = NULL;
      rtrn = s21_sum_matrix(A, &B, &res);
      ck_assert_int_eq(rtrn, return_check[_i]);
      s21_remove_matrix(&B);
    }
  }

  if (_i == (RESULT_COUNT + CALC_COUNT + INCOR_COUNT - 1)) {
    double temp[] = {1, 2, 3, 4, 5, 6};
    matrix_t A;
    A.matrix = NULL;
    matrix_t B;
    B.matrix = NULL;
    matrix_t *res;
    error_A = s21_create_matrix(2, 3, &A);
    if (!error_A) s21_set_matrix(&A, temp);
    error_B = s21_create_matrix(2, 3, &B);
    if (!error_B) s21_set_matrix(&B, temp);

    res = NULL;
    rtrn = s21_sum_matrix(&A, &B, res);
    ck_assert_int_eq(rtrn, return_check[_i]);

    if (!error_A) s21_remove_matrix(&A);
    if (!error_B) s21_remove_matrix(&B);
  }

  if (_i < (RESULT_COUNT + CALC_COUNT)) {
    matrix_t A;
    A.matrix = NULL;
    matrix_t B;
    B.matrix = NULL;
    matrix_t C;
    C.matrix = NULL;
    matrix_t res;

    error_A = s21_create_matrix(rang_a[_i][0], rang_a[_i][1], &A);
    if (!error_A) s21_set_matrix(&A, values_a[_i]);
    error_B = s21_create_matrix(rang_b[_i][0], rang_b[_i][1], &B);
    if (!error_B) s21_set_matrix(&B, values_b[_i]);

    if (_i < RESULT_COUNT) {
      error_C = s21_create_matrix(rang_c[_i][0], rang_c[_i][1], &C);
      if (!error_C) s21_set_matrix(&C, values_c[_i]);
    }

    rtrn = s21_sum_matrix(&A, &B, &res);
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
    if (!error_B) s21_remove_matrix(&B);
    if (!error_C && _i < RESULT_COUNT) s21_remove_matrix(&C);
    if (!rtrn) s21_remove_matrix(&res);
  }
}
END_TEST

Suite *test_sum_suite(void) {
  Suite *s;
  TCase *tc_result;

  s = suite_create(" + sum");
  tc_result = tcase_create("\n==sum== -result-\n");

  tcase_set_timeout(tc_result, TEST_TIMEOUT);
  tcase_add_loop_test(tc_result, test_sum_result, 0,
                      RESULT_COUNT + CALC_COUNT + INCOR_COUNT);
  suite_add_tcase(s, tc_result);
  return s;
}
