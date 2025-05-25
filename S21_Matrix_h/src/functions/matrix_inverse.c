#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (is_correct(A) || (result == NULL)) res = INCORRECT;
  if (!res)
    if (calc_is_square(A)) res = ERROR_CALCULATE;

  double det = 0;
  if (!res) {
    res = s21_determinant(A, &det);
    if (!res)
      if (!det) res = ERROR_CALCULATE;
  }

  if (!res) {
    matrix_t T1, T2;
    int temp_res_1 = -1;
    int temp_res_2 = -1;

    if (A->rows > 1) {
      temp_res_1 = s21_calc_complements(A, &T1);
      if (!temp_res_1) temp_res_2 = s21_transpose(&T1, &T2);
      if (!temp_res_1 && !temp_res_2)
        res = s21_mult_number(&T2, 1 / det, result);
    } else {
      res = s21_create_matrix(A->rows, A->rows, result);
      if (!res) result->matrix[0][0] = 1 / det;
    }

    if (temp_res_1 == 0) s21_remove_matrix(&T1);
    if (temp_res_2 == 0) s21_remove_matrix(&T2);
  }

  return res;
}