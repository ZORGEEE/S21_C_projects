#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (is_correct_both(A, B) || result == NULL) res = INCORRECT;
  if (!res)
    if (calc_is_compatible_size(A, B)) res = ERROR_CALCULATE;

  if (!res) {
    res = s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; !res && i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }

  return res;
}