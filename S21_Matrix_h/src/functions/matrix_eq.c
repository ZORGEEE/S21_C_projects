#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;

  if (!is_correct_both(A, B) && !calc_is_equal_size(A, B)) {
    for (int i = 0; res && i < A->rows; i++) {
      for (int j = 0; res && j < A->columns; j++) {
        if (abs_double(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) res = FAILURE;
      }
    }
  } else {
    res = FAILURE;
  }

  return res;
}