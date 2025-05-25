#include "tests.h"

START_TEST(int_decimal_test) {
  {
    int src = 2147483647;
    s21_decimal check = {{2147483647, 0, 0, 0}};
    s21_decimal result;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, SUCCESS);
  }

  {
    int src = -2147483648;
    s21_decimal check = {{2147483648, 0, 0, 0}};
    setsign(&check);
    s21_decimal result;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, SUCCESS);
  }

  {
    int src = -49135648;
    s21_decimal check = {{49135648, 0, 0, 0}};
    setsign(&check);
    s21_decimal result;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, SUCCESS);
  }

  {
    s21_decimal value = {{49135648, 0, 0, 0}};
    setsign(&value);
    set_scale(&value, 1);
    int dst;
    int check = -4913564;
    int return_value = s21_from_decimal_to_int(value, &dst);
    ck_assert_int_eq(dst, check);
    ck_assert_int_eq(return_value, 0);
  }

  {
    s21_decimal value = {{49135648, 0, 0, 0}};
    set_scale(&value, 1);
    int dst;
    int check = 4913564;
    int return_value = s21_from_decimal_to_int(value, &dst);
    ck_assert_int_eq(dst, check);
    ck_assert_int_eq(return_value, 0);
  }
}
END_TEST

START_TEST(float_decimal_test) {
  {
    s21_decimal value = {{9, 0, 0, 0}};
    set_scale(&value, 1);
    setsign(&value);
    float a = -0.9, b;
    int res = s21_from_decimal_to_float(value, &b);
    ck_assert_float_eq(a, b);
    ck_assert_int_eq(res, 0);
  }

  {
    s21_decimal value = {{0, 0, 0, 0}};
    s21_decimal value_2 = {{9, 0, 0, 0}};
    set_scale(&value_2, 1);
    setsign(&value_2);
    float a = -0.9;
    int res = s21_from_float_to_decimal(a, &value);
    ck_assert_int_eq(s21_is_equal(value_2, value), 1);
    ck_assert_int_eq(res, 0);
  }
}
END_TEST

Suite *s21_conversion_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("S21 Conversion");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, int_decimal_test);
  tcase_add_test(tc_core, float_decimal_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int test_conversion() {
  int no_failed = 0;
  Suite *s;
  SRunner *sr;

  s = s21_conversion_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return no_failed;
}