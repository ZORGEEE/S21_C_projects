#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = result == NULL ? INCORRECT : OK;
  if (!res) {
    res = ((rows > 0) && (columns > 0)) ? OK : INCORRECT;
  }
  if (!res) {
    double **m = (double **)calloc(rows, sizeof(double *));
    if (m == NULL) res = INCORRECT;

    if (!res) {
      for (int i = 0; !res && i < rows; i++) {
        double *r = (double *)calloc(columns, sizeof(double));
        if (r == NULL) res = INCORRECT;
        m[i] = r;
      }
      if (res)
        for (int i = 0; i < rows; i++) free(m[i]);
    }

    if (!res) {
      result->matrix = m;
      result->columns = columns;
      result->rows = rows;
    }
  }

  return res;
}