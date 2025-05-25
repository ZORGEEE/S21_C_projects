#include "../s21_unit_tests.h"

#define RESULT_COUNT 9
#define CALC_COUNT 4
#define INCOR_COUNT 2

START_TEST(test_inverse_result) {
  //=================-Значения для тестов-=============================
  static const double values_a[RESULT_COUNT + CALC_COUNT][MAX_RANG] = {
      {1.234567, 2, -40, 3.9000999},
      {1, 2, 3, 0, 4, 2, 5, 2, 1},
      {1, 0, 0, 0, 1, 0, 0, 0, -1},
      {2, 5, 7, 6, 3, 4, 5, -2, -3},
      {1, 5, 6,  93, 3,  -34, 8, -1, 0, 0, -9, 3, 45, 3,  -3, -19, -40, -200,
       3, 9, 23, 45, 15, 22,  6, 7,  2, 8, 0,  0, -9, -7, 1,  1,   99,  12},
      {8},
      {2, 4, 6, -1},
      {0, 14, 7, -9, 6, 2, 0, 1, 0, 0, 12, 4, -3, -8, 0, 0},
      {0, 0, 4, 0, 3, 0, 1, 0, 0},

      {4, 6, 8, 9},
      {6, 7, 8, 9, 10, 11, 12, 8, 9, 1},
      {1, 2, 3, 4, 5, 6, 7, 8, 9},
      {4, 5, 8, 10},
  };

  static const int rang_a[RESULT_COUNT + CALC_COUNT][2] = {
      {2, 2}, {3, 3}, {3, 3}, {3, 3}, {6, 6}, {1, 1}, {2, 2}, {4, 4}, {3, 3},

      {1, 4}, {2, 5}, {3, 3}, {2, 2}};

  static const double values_c[RESULT_COUNT][MAX_RANG] = {
      {0.045983645649965, -0.023580752713521, 0.47161505427043,
       0.014556009567637},
      {0, -0.1, 0.2, -0.25, 0.35, 0.05, 0.5, -0.2, -0.1},
      {1, 0, 0, 0, 1, 0, 0, 0, -1},
      {1, -1, 1, -38, 41, -34, 27, -29, 24},
      {-339791.0 / 349417038.0,   36605855.0 / 349417038.0,
       246453.0 / 116472346.0,    -1698623.0 / 698834076.0,
       30038207.0 / 1048251114.0, 22593097.0 / 2096502228.0,
       -1296305.0 / 174708519.0,  -17282773.0 / 174708519.0,
       -105591.0 / 58236173.0,    -3534095.0 / 349417038.0,
       73292606.0 / 524125557.0,  -8352803.0 / 1048251114.0,
       -3344312.0 / 174708519.0,  -3702511.0 / 174708519.0,
       508335.0 / 58236173.0,     19604869.0 / 349417038.0,
       -37503427.0 / 524125557.0, -6625817.0 / 1048251114.0,
       1398511.0 / 116472346.0,   1547239.0 / 116472346.0,
       -254223.0 / 116472346.0,   -781267.0 / 232944692.0,
       -111957.0 / 116472346.0,   109499.0 / 232944692.0,
       -71171.0 / 174708519.0,    8291.0 / 174708519.0,
       32254.0 / 58236173.0,      -473015.0 / 349417038.0,
       6471617.0 / 524125557.0,   11055439.0 / 1048251114.0,
       -192560.0 / 174708519.0,   3692315.0 / 174708519.0,
       -267039.0 / 58236173.0,    -166123.0 / 174708519.0,
       3794777.0 / 524125557.0,   128960.0 / 524125557.0},
      {1.0 / 8.0},
      {0.03846154, 0.15384615, 0.23076923, -0.07692308},
      {4.0 / 217.0, 136.0 / 651.0, -1.0 / 93.0, 55.0 / 651.0, -3.0 / 434.0,
       -17.0 / 217.0, 1.0 / 248.0, -34.0 / 217.0, 1.0 / 31.0, 1.0 / 31.0,
       2.0 / 31.0, 2.0 / 31.0, -3.0 / 31.0, -3.0 / 31.0, 7.0 / 124.0,
       -6.0 / 31.0},
      {0, 0, 1, 0, 1.0 / 3.0, 0, 0.25, 0, 0},
  };

  static const int rang_c[RESULT_COUNT][2] = {
      {2, 2}, {3, 3}, {3, 3}, {3, 3}, {6, 6}, {1, 1}, {2, 2}, {4, 4}, {3, 3},
  };

  static const int return_check[RESULT_COUNT + CALC_COUNT + INCOR_COUNT] = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 1, 1,
  };

  int rtrn = -1;
  int error_A = 0;
  int error_C = 0;

  if (_i == (RESULT_COUNT + CALC_COUNT)) {
    matrix_t *A = NULL;
    matrix_t res;

    rtrn = s21_inverse_matrix(A, &res);
    ck_assert_int_eq(rtrn, return_check[_i]);
  }

  if (_i == (RESULT_COUNT + CALC_COUNT + INCOR_COUNT - 1)) {
    double temp[] = {1, 2, 3, 4};
    matrix_t A;
    matrix_t *res = NULL;
    error_A = s21_create_matrix(2, 2, &A);
    if (!error_A) {
      s21_set_matrix(&A, temp);
      rtrn = s21_inverse_matrix(&A, res);
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

    rtrn = s21_inverse_matrix(&A, &res);
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

Suite *test_inverse_suite(void) {
  Suite *s;
  TCase *tc_result;

  s = suite_create(" + inverse");
  tc_result = tcase_create("\n==inverse== -result-\n");

  tcase_set_timeout(tc_result, TEST_TIMEOUT);
  tcase_add_loop_test(tc_result, test_inverse_result, 0,
                      RESULT_COUNT + CALC_COUNT + INCOR_COUNT);
  suite_add_tcase(s, tc_result);
  return s;
}
