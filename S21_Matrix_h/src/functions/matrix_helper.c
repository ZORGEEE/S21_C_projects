#include "../s21_matrix.h"

double abs_double(double src) { return src < 0 ? src * (-1) : src; }

int pow_minus_one(int rank) { return rank % 2 == 0 ? 1 : -1; }

int s21_copy_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;

  if (is_correct(A) || result == NULL) res = INCORRECT;

  if (!res) {
    res = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; !res && i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j];
      }
    }
  }

  return res;
}

int is_correct(matrix_t *A) {
  int res = INCORRECT;

  if ((A != NULL) && (A->matrix != NULL) && (A->rows > 0) && (A->columns > 0)) {
    res = OK;
  }

  return res;
}

int is_correct_both(matrix_t *A, matrix_t *B) {
  int res = INCORRECT;

  if (!is_correct(A) && !is_correct(B)) {
    res = OK;
  }

  return res;
}

int calc_is_equal_size(matrix_t *A, matrix_t *B) {
  int res = ERROR_CALCULATE;

  if ((A->rows == B->rows) && (A->columns == B->columns)) {
    res = OK;
  }

  return res;
}

int calc_is_compatible_size(matrix_t *A, matrix_t *B) {
  int res = ERROR_CALCULATE;

  if (A->columns == B->rows) {
    res = OK;
  }

  return res;
}

int calc_is_square(matrix_t *A) {
  int res = ERROR_CALCULATE;

  if (A->rows == A->columns) {
    res = OK;
  }

  return res;
}