#include "s21_unit_tests.h"

int main() {
  Suite *s[] = {test_create_suite(),
                test_remove_suite(),
                test_eq_suite(),
                test_sub_suite(),
                test_sum_suite(),
                test_mult_matrix_suite(),
                test_mult_number_suite(),
                test_transpose_suite(),
                test_calc_complements_suite(),
                test_determinant_suite(),
                test_inverse_suite(),
                NULL};

  printf("\nTESTS MODULE\n\n");
  SRunner *sr;
  sr = srunner_create(s[0]);
  for (int i = 1; s[i] != NULL; i++) srunner_add_suite(sr, s[i]);

  srunner_set_fork_status(sr, CK_FORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);

  return 0;
}

void s21_set_matrix(matrix_t *A, const double *src) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = src[i * A->columns + j];
    }
  }
}