#include "../s21_unit_tests.h"

#define RESULT_COUNT 7
#define CALC_COUNT 0
#define INCOR_COUNT 0

START_TEST(test_eq_result) {
  static const double values_a[RESULT_COUNT + CALC_COUNT][MAX_RANG] = {
      {2, 3, 4, 5, 6, 7, 8, 9, 0.0000001},
      {1, 6, 8, 2, 5, 2, 5, 1, 343534535345},
      {3.49999, 5.023424, 7.3563, 0.00005399, 564.34, 34.2345246, 0.5466463,
       34.5435, -9.3424, -0.00000019},
      {1, 0, 0, 0, 1, 0, 0, 0, 1},
      {8},
      {1, 2},
      {1, 2, 3, 4}};

  static const int rang_a[RESULT_COUNT + CALC_COUNT][2] = {
      {3, 3}, {3, 3}, {5, 2}, {9, 1}, {1, 1}, {1, 2}, {2, 2}};

  static const double values_b[RESULT_COUNT + CALC_COUNT][MAX_RANG] = {
      {2, 3, 4, 5, 6, 7, 8, 9, 0.0000009},
      {1, 6, 8, 2, 5, 2, 5, 1, 343534535345},
      {3.49999, 5.023424, 7.3563, 0.00005399, 564.34, 34.2345246, 0.5466463,
       34.5435, -9.3424, -0.00000019},
      {1, 0, 0, 0, 1, 0, 0, 0, 1},
      {8},
      {2, 2},
      {1, 2, 3, 4}};

  static const int rang_b[RESULT_COUNT + CALC_COUNT][2] = {
      {3, 3}, {3, 3}, {5, 2}, {9, 1}, {1, 1}, {1, 2}, {1, 4}};

  static const int return_check[RESULT_COUNT + CALC_COUNT + INCOR_COUNT] = {
      0, 1, 1, 1, 1, 0, 0};

  int rtrn = -1;
  int error_A = 0;
  int error_B = 0;

  matrix_t A;
  A.matrix = NULL;
  matrix_t B;
  B.matrix = NULL;

  error_A = s21_create_matrix(rang_a[_i][0], rang_a[_i][1], &A);
  if (!error_A) s21_set_matrix(&A, values_a[_i]);
  error_B = s21_create_matrix(rang_b[_i][0], rang_b[_i][1], &B);
  if (!error_B) s21_set_matrix(&B, values_b[_i]);

  rtrn = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(rtrn, return_check[_i]);

  if (!error_A) s21_remove_matrix(&A);
  if (!error_B) s21_remove_matrix(&B);
}
END_TEST

Suite *test_eq_suite(void) {
  Suite *s;
  TCase *tc_result;

  s = suite_create(" + eq");
  tc_result = tcase_create("\n==eq== -result-\n");

  tcase_set_timeout(tc_result, TEST_TIMEOUT);
  tcase_add_loop_test(tc_result, test_eq_result, 0,
                      RESULT_COUNT + CALC_COUNT + INCOR_COUNT);
  suite_add_tcase(s, tc_result);
  return s;
}
