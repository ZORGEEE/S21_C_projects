#include "../s21_unit_tests.h"

#define RESULT_COUNT 2
#define CALC_COUNT 3
#define INCOR_COUNT 1

START_TEST(test_create_result) {
  static const double rows[RESULT_COUNT + CALC_COUNT] = {3, 100, 0, 5, -2};

  static const double columns[RESULT_COUNT + CALC_COUNT] = {3, 100, 5, 0, -4};

  static const int return_check[RESULT_COUNT + CALC_COUNT + INCOR_COUNT] = {
      0, 0, 1, 1, 1, 1};

  int rtrn = -1;

  if (_i == (RESULT_COUNT + CALC_COUNT)) {
    matrix_t *res = NULL;
    int row = 1;
    int column = 2;

    rtrn = s21_create_matrix(row, column, res);
    ck_assert_int_eq(rtrn, return_check[_i]);
  }

  if (_i < (RESULT_COUNT + CALC_COUNT)) {
    int row = rows[_i];
    int column = columns[_i];
    matrix_t res;

    rtrn = s21_create_matrix(row, column, &res);
    ck_assert_int_eq(rtrn, return_check[_i]);

    if (!rtrn) s21_remove_matrix(&res);
  }
}
END_TEST

Suite *test_create_suite(void) {
  Suite *s;
  TCase *tc_result;

  s = suite_create("\n  + create");
  tc_result = tcase_create("\n==create== -result-\n");

  tcase_set_timeout(tc_result, TEST_TIMEOUT);
  tcase_add_loop_test(tc_result, test_create_result, 0,
                      RESULT_COUNT + CALC_COUNT + INCOR_COUNT);
  suite_add_tcase(s, tc_result);
  return s;
}
