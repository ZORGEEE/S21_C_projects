#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = OK;
  if (is_correct(A) || result == NULL) res = INCORRECT;
  if (!res)
    if (calc_is_square(A)) res = ERROR_CALCULATE;

  if (!res) {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else {
      matrix_t C;
      res = s21_copy_matrix(A, &C);
      if (!res) {
        *result = 1;
        int zero_flag = 1;

        for (int m = 0; zero_flag && (m < (C.rows - 1)); m++) {
          if (!C.matrix[m][m]) {
            zero_flag = gauss_swap_string(m, m, &C, -1, -1, result);
          }
          if (zero_flag) gauss_substract_string(m, m, &C, -1, -1);
        }

        if (zero_flag) {
          for (int i = 0; i < C.rows; i++) {
            *result *= C.matrix[i][i];
          }
        } else {
          *result = 0;
        }

        s21_remove_matrix(&C);
      }
    }
  }
  return res;
}