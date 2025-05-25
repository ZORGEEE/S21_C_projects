#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (is_correct(A) || result == NULL) res = INCORRECT;
  if (!res)
    if (calc_is_square(A) || (A->rows == 1)) res = ERROR_CALCULATE;

  if (!res) {
    res = s21_create_matrix(A->rows, A->rows, result);
    if (!res) {
      double temp = 0;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->rows; j++) {
          res = determinant_for_minor(A, i, j, &temp);
          if (!res) result->matrix[i][j] = temp * pow_minus_one(i + j);
        }
      }
    }
  }

  return res;
}