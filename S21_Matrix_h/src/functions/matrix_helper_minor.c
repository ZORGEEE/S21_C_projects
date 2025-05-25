#include "../s21_matrix.h"

int determinant_for_minor(matrix_t *A, int ii, int jj, double *result) {
  int res = OK;
  if (is_correct(A) || result == NULL) res = INCORRECT;
  if (!res)
    if (calc_is_square(A) || (A->rows == 1)) res = ERROR_CALCULATE;

  if (!res) {
    if (A->rows == 2) {
      *result = A->matrix[A->rows - 1 - ii][A->columns - 1 - jj];
    } else {
      matrix_t C;
      res = s21_copy_matrix(A, &C);
      if (!res) {
        *result = 1;
        int zero_flag = 1;

        int m = 0;
        int n = 0;
        for (int k = 0; zero_flag && k < (C.rows - 1); k++) {
          if (m == ii) m++;
          if (n == jj) n++;
          if (!C.matrix[m][n]) {
            zero_flag = gauss_swap_string(m, n, &C, ii, jj, result);
          }
          if (zero_flag) gauss_substract_string(m, n, &C, ii, jj);
          m++;
          n++;
        }

        if (zero_flag) {
          int i = 0;
          int j = 0;
          for (int k = 0; k < (C.rows - 1); k++) {
            if (i == ii) i++;
            if (j == jj) j++;
            *result *= C.matrix[i][j];
            i++;
            j++;
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

int gauss_swap_string(int mm, int nn, matrix_t *C, int ii, int jj,
                      double *result) {
  int not_zero_flag = 1;
  for (int k = mm; not_zero_flag & (k < C->rows); k++) {
    if (k != ii && C->matrix[k][nn] != 0) {
      not_zero_flag = 0;
      double temp;
      for (int l = nn; l < C->rows; l++) {
        if (l != jj) {
          temp = C->matrix[k][l];
          C->matrix[k][l] = C->matrix[mm][l];
          C->matrix[mm][l] = temp;
        }
      }
      *result *= -1;
    }
  }
  return not_zero_flag ? 0 : 1;
}

void gauss_substract_string(int mm, int nn, matrix_t *C, int ii, int jj) {
  for (int i = mm + 1; i < C->rows; i++) {
    if (i != ii) {
      double temp = C->matrix[i][nn] / C->matrix[mm][nn];
      for (int j = nn; j < C->rows; j++) {
        if (j != jj) {
          C->matrix[i][j] = C->matrix[i][j] - C->matrix[mm][j] * temp;
        }
      }
    }
  }
}