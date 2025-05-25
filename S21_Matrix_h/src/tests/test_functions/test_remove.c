#include "../s21_unit_tests.h"

#define RESULT_COUNT 1

START_TEST(test_remove_result) {
  int row = 3;
  int column = 4;
  matrix_t A;
  int rtrn = s21_create_matrix(row, column, &A);

  if (!rtrn) {
    s21_remove_matrix(&A);
    ck_assert_int_eq(A.rows, 0);
    ck_assert_int_eq(A.columns, 0);
    ck_assert_ptr_null(A.matrix);
  }
}
END_TEST

Suite *test_remove_suite(void) {
  Suite *s;
  TCase *tc_result;

  s = suite_create(" + remove");
  tc_result = tcase_create("\n==remove== -result-\n");

  tcase_set_timeout(tc_result, TEST_TIMEOUT);
  tcase_add_loop_test(tc_result, test_remove_result, 0, RESULT_COUNT);
  suite_add_tcase(s, tc_result);
  return s;
}
