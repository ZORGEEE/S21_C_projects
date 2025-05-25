#include "../s21_unit_tests.h"

#define RESULT_COUNT 10
#define CALC_COUNT 3
#define INCOR_COUNT 2

START_TEST(test_calc_complements_result) {
  static const double values_a[RESULT_COUNT + CALC_COUNT][MAX_RANG] = {
      {1.234567, 2, -40, 3.9000999},
      {1, 2, 3, 0, 4, 2, 5, 2, 1},
      {1, 0, 0, 0, 1, 0, 0, 0, -1},
      {2, 4, 6, -1},
      {0, 14, 7, -9, 6, 2, 0, 1, 0, 0, 12, 4, -3, -8, 0, 0},
      {4, 5, 8, 10},
      {1, 1, 1, 1, 1, 1, 1, 1, 1},
      {0, 0, 4, 0, 3, 0, 1, 0, 0},
      {1, 0, 0, 1},
      {1, 2, 4, -5},

      {8},
      {4, 6, 8, 9},
      {6, 7, 8, 9, 10, 11, 12, 8, 9, 1},
  };

  static const int rang_a[RESULT_COUNT + CALC_COUNT][2] = {
      {2, 2}, {3, 3}, {3, 3}, {2, 2}, {4, 4},
      {2, 2}, {3, 3}, {3, 3}, {2, 2}, {2, 2},

      {1, 1}, {1, 4}, {5, 2},
  };

  static const double values_c[RESULT_COUNT][MAX_RANG] = {
      {3.9000999, 40, -2, 1.234567},
      {0, 10, -20, 4, -14, 8, -8, -2, 4},
      {-1, 0, 0, 0, -1, 0, 0, 0, 1},
      {-1, -6, -4, 2},
      {96, -36, 168, -504, 1088, -408, 168, -504, -56, 21, 336, 294, 440, -816,
       336, -1008},
      {10, -8, -5, 4},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, -3, 0, -4, 0, -12, 0, 0},
      {1, 0, 0, 1},
      {-5, -4, -2, 1}};

  static const int rang_c[RESULT_COUNT][2] = {{2, 2}, {3, 3}, {3, 3}, {2, 2},
                                              {4, 4}, {2, 2}, {3, 3}, {3, 3},
                                              {2, 2}, {2, 2}};

  static const int return_check[RESULT_COUNT + CALC_COUNT + INCOR_COUNT] = {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 1,
  };

  int rtrn = -1;
  int error_A = 0;
  int error_C = 0;

  if (_i == (RESULT_COUNT + CALC_COUNT)) {
    matrix_t *A = NULL;
    matrix_t res;

    rtrn = s21_calc_complements(A, &res);
    ck_assert_int_eq(rtrn, return_check[_i]);
  }

  if (_i == (RESULT_COUNT + CALC_COUNT + INCOR_COUNT - 1)) {
    double temp[] = {1, 2, 3, 4};
    matrix_t A;
    matrix_t *res = NULL;
    error_A = s21_create_matrix(2, 2, &A);
    if (!error_A) {
      s21_set_matrix(&A, temp);
      rtrn = s21_calc_complements(&A, res);
      ck_assert_int_eq(rtrn, return_check[_i]);
      s21_remove_matrix(&A);
    }
  }

  if (_i < (RESULT_COUNT + CALC_COUNT)) {
    matrix_t A;
    A.matrix = NULL;
    matrix_t C;
    A.matrix = NULL;
    matrix_t res;

    error_A = s21_create_matrix(rang_a[_i][0], rang_a[_i][1], &A);
    if (!error_A) s21_set_matrix(&A, values_a[_i]);

    if (_i < RESULT_COUNT) {
      error_C = s21_create_matrix(rang_c[_i][0], rang_c[_i][1], &C);
      if (!error_C) s21_set_matrix(&C, values_c[_i]);
    }

    rtrn = s21_calc_complements(&A, &res);
    ck_assert_int_eq(rtrn, return_check[_i]);

    if (!rtrn) {
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

Suite *test_calc_complements_suite(void) {
  Suite *s;
  TCase *tc_result;

  s = suite_create(" + calc_complements");
  tc_result = tcase_create("\n==calc_complements== -result-\n");

  tcase_set_timeout(tc_result, TEST_TIMEOUT);
  tcase_add_loop_test(tc_result, test_calc_complements_result, 0,
                      RESULT_COUNT + CALC_COUNT + INCOR_COUNT);
  suite_add_tcase(s, tc_result);
  return s;
}
