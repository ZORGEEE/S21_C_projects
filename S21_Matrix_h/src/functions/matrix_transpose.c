#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (is_correct(A) || result == NULL) res = INCORRECT;

  if (!res) {
    res = s21_create_matrix(A->columns, A->rows, result);

    for (int j = 0; !res && j < A->columns; j++) {
      for (int i = 0; i < A->rows; i++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }

  return res;
}