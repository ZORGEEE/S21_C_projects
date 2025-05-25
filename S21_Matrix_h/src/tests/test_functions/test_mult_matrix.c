#include "../s21_unit_tests.h"

#define RESULT_COUNT 5
#define CALC_COUNT 2
#define INCOR_COUNT 3

START_TEST(test_mult_matrix_result) {
  static const double values_a[RESULT_COUNT + CALC_COUNT][MAX_RANG] = {
      {2, 3, 4, 5, 6, 7, 8, 9, 0},
      {1, 6, 8, 2, 5, 2, 5, 1, 5},
      {3.49999, 5.023424, 7.3563, 0.00005399, 564.34, 34.2345246, 0.5466463,
       34.5435, -9.3424, -0.00000001},
      {1, 0, 0, 0, 1, 0, 0, 0, 1},
      {8},

      {4, 6, 8, 9},
      {6, 7, 8, 9, 10, 11, 12, 8, 9},
  };

  static const int rang_a[RESULT_COUNT + CALC_COUNT][2] = {
      {3, 3}, {3, 3}, {5, 2}, {9, 1}, {1, 1},

      {1, 4}, {3, 3},
  };

  static const double values_b[RESULT_COUNT + CALC_COUNT][MAX_RANG] = {
      {-1, -9, 0, 0, 1, 1, 0, 5, 4},
      {1, 0.001, 43.432, 5.98, 2.665, -0.0004, 1, 5, 9.99999},
      {2.342, 8.0908, -34.65, -0.000259, -6.453, 0, 0, 0},
      {7},
      {10.000001},

      {9, 0, 0, 1, 4, 7},
      {1, 2, 3, 6},
  };

  static const int rang_b[RESULT_COUNT + CALC_COUNT][2] = {
      {3, 3}, {3, 3}, {2, 4}, {1, 1}, {1, 1},

      {2, 3}, {2, 2},
  };

  static const double values_c[RESULT_COUNT][MAX_RANG] = {
      {-2, 5, 19, -5, -4, 34, -8, -63, 9},
      {1122.0 / 25.0, 55991.0 / 1000.0, 1542869.0 / 12500.0, 339.0 / 10.0,
       23327.0 / 1000.0, 5343099.0 / 50000.0, 799.0 / 50.0, 2767.0 / 100.0,
       5343191.0 / 20000.0},
      {(-6054794623.0) / 250000000.0,
       7079429773.0 / 250000000.0,
       (-242549307.0) / 2000000.0,
       (-90649741.0) / 100000000000.0,
       1722810620253.0 / 100000000000.0,
       1487958801.0 / 25000000.0,
       (-50979159.0) / 200000.0,
       (-19052817.0) / 10000000000.0,
       5503844463781.0 / 5000000000.0,
       570745259.0 / 125000.0,
       (-19554381.0) / 1000.0,
       (-7308203.0) / 50000000.0,
       (-1108144799327.0) / 5000000000.0,
       110570147101.0 / 25000000000.0,
       (-3788258859.0) / 200000000.0,
       (-1415813917.0) / 10000000000000.0,
       (-2187990073547.0) / 100000000000.0,
       (-118105453.0) / 1562500.0,
       4046427.0 / 12500.0,
       1512301.0 / 625000000.0},
      {7, 0, 0, 0, 7, 0, 0, 0, 7},
      {10000001.0 / 125000}};

  static const int rang_c[RESULT_COUNT][2] = {
      {3, 3}, {3, 3}, {5, 4}, {9, 1}, {1, 1}};

  static const int return_check[RESULT_COUNT + CALC_COUNT + INCOR_COUNT] = {
      0, 0, 0, 0, 0, 2, 2, 1, 1, 1};

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
      rtrn = s21_mult_matrix(&A, B, &res);
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
      rtrn = s21_mult_matrix(A, &B, &res);
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
    rtrn = s21_mult_matrix(&A, &B, res);
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

    rtrn = s21_mult_matrix(&A, &B, &res);
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

Suite *test_mult_matrix_suite(void) {
  Suite *s;
  TCase *tc_result;

  s = suite_create(" + mult_matrix");
  tc_result = tcase_create("\n=mult_matrix== -result-\n");

  tcase_set_timeout(tc_result, TEST_TIMEOUT);
  tcase_add_loop_test(tc_result, test_mult_matrix_result, 0,
                      RESULT_COUNT + CALC_COUNT + INCOR_COUNT);
  suite_add_tcase(s, tc_result);
  return s;
}
