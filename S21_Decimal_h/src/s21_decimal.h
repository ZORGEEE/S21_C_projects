#ifndef C5_S21_DECIMAL_0_S21_DECIMAL_H
#define C5_S21_DECIMAL_0_S21_DECIMAL_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define s21_MAXDEC 2e96 - 1

#define ERROR

typedef struct {
  unsigned int bits[4];
} s21_decimal;

enum arithmetic_errors { OK, MORE, LESS, DIVZERO };

enum comparison_errors { FALSE, TRUE };

enum conversion_errors { CONVERR = 1 };

enum other_errors { CALCERR = 1 };

// s21_arithmetic.c
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// s21_comparison.c
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

// s21_transformation.c
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// s21_other.c
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// help.c
int s21_get_sign(s21_decimal value);
int s21_get_exp(s21_decimal value);
int s21_set_exp(s21_decimal *value, int exp);
int s21_set_sign(s21_decimal *value);
int s21_clear_decimal(s21_decimal *value);
int s21_get_bit(s21_decimal value, int n, int byteNum);
int s21_getBit(s21_decimal num, int curBit);
int s21_set_bit(s21_decimal *value, int n, int byteNum);
int s21_addition(int bit1, int bit2, int *remainder);
int s21_left_shift(s21_decimal *value);
int s21_copy_to_buffer(s21_decimal value, s21_decimal *dest);
int s21_copy_to_buffer_no_exp(s21_decimal value, s21_decimal *dest);
int s21_decimal_pow(s21_decimal *value, int n);
int s21_invert_decimal(s21_decimal *value);
int s21_zero_decimal(s21_decimal value_1, s21_decimal value_2);

// for tests
int setsign(s21_decimal *val);
int set_scale(s21_decimal *val, int sign);

#endif  // C5_S21_DECIMAL_0_S21_DECIMAL_H
