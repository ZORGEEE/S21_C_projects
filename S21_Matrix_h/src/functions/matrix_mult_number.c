#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = OK;
  if (is_correct(A) || result == NULL) res = INCORRECT;

  if (!res) {
    res = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; !res && i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = number * A->matrix[i][j];
      }
    }
  }

  return res;
}