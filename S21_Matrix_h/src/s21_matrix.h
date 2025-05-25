#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <stdlib.h>

#define OK 0         // 0 - OK
#define INCORRECT 1  // 1 - Ошибка, некорректная матрица
#define ERROR_CALCULATE 2  // 2 - Ошибка вычисления

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// helper functions

double abs_double(double src);
int pow_minus_one(int rank);
int is_correct(matrix_t *A);
int is_correct_both(matrix_t *A, matrix_t *B);
int calc_is_equal_size(matrix_t *A, matrix_t *B);
int calc_is_compatible_size(matrix_t *A, matrix_t *B);
int calc_is_square(matrix_t *A);
int gauss_swap_string(int mm, int nn, matrix_t *C, int ii, int jj,
                      double *result);
void gauss_substract_string(int mm, int nn, matrix_t *C, int ii, int jj);
int determinant_for_minor(matrix_t *A, int ii, int jj, double *result);

int s21_copy_matrix(matrix_t *A, matrix_t *result);

// main functions

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif
