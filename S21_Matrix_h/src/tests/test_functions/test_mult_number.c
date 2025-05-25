#include "../s21_unit_tests.h"

#define RESULT_COUNT 3
#define CALC_COUNT 0
#define INCOR_COUNT 2

START_TEST(test_mult_number_result) {
  static const double values_a[RESULT_COUNT + CALC_COUNT][MAX_RANG] = {
      {3.49999, 5.023424, 7.3563, 0.00005399, 564.34, 34.2345246, 0.5466463,
       34.5435, -9.3424, -0.00000001},
      {2, 3, 4, 5, 6, 7, 8, 9, 0},
      {8},
  };

  static const int rang_a[RESULT_COUNT + CALC_COUNT][2] = {
      {2, 5},
      {3, 3},
      {1, 1},
  };

  static const double values_b[RESULT_COUNT + CALC_COUNT] = {0, 1.23999999,
                                                             -123344.5};

  static const double values_c[RESULT_COUNT][MAX_RANG] = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {2.47999998, 3.71999997, 4.95999996, 6.19999995, 7.43999994, 8.67999993,
       9.91999992, 11.15999991, 0},
      {-986756},
  };

  static const int rang_c[RESULT_COUNT][2] = {{2, 5}, {3, 3}, {1, 1}};

  static const int return_check[RESULT_COUNT + CALC_COUNT + INCOR_COUNT] = {
      0, 0, 0, 1, 1,
  };

  int rtrn = -1;
  int error_A = 0;
  int error_C = 0;

  if (_i == (RESULT_COUNT + CALC_COUNT)) {
    matrix_t *A = NULL;
    double b = 23;
    matrix_t res;

    rtrn = s21_mult_number(A, b, &res);
    ck_assert_int_eq(rtrn, return_check[_i]);
  }

  if (_i == (RESULT_COUNT + CALC_COUNT + INCOR_COUNT - 1)) {
    double temp[] = {1, 2, 3, 4, 5, 6};
    matrix_t A;
    double b = 23;
    matrix_t *res = NULL;
    error_A = s21_create_matrix(2, 3, &A);
    if (!error_A) {
      s21_set_matrix(&A, temp);
      rtrn = s21_mult_number(&A, b, res);
      ck_assert_int_eq(rtrn, return_check[_i]);
      s21_remove_matrix(&A);
    }
  }

  if (_i < (RESULT_COUNT + CALC_COUNT)) {
    matrix_t A;
    A.matrix = NULL;
    double b;
    matrix_t C;
    C.matrix = NULL;
    matrix_t res;

    error_A = s21_create_matrix(rang_a[_i][0], rang_a[_i][1], &A);
    if (!error_A) s21_set_matrix(&A, values_a[_i]);

    b = values_b[_i];

    if (_i < RESULT_COUNT) {
      error_C = s21_create_matrix(rang_c[_i][0], rang_c[_i][1], &C);
      if (!error_C) s21_set_matrix(&C, values_c[_i]);
    }

    rtrn = s21_mult_number(&A, b, &res);
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

Suite *test_mult_number_suite(void) {
  Suite *s;
  TCase *tc_result;

  s = suite_create(" + mult_number");
  tc_result = tcase_create("\n==mult_number== -result-\n");

  tcase_set_timeout(tc_result, TEST_TIMEOUT);
  tcase_add_loop_test(tc_result, test_mult_number_result, 0,
                      RESULT_COUNT + CALC_COUNT + INCOR_COUNT);
  suite_add_tcase(s, tc_result);
  return s;
}
