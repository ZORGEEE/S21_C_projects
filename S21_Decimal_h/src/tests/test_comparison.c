#include "tests.h"

START_TEST(s21_is_less_test) {
  {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    int return_value = s21_is_less(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
  }

  {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    setsign(&value_1);
    int return_value = s21_is_less(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    setsign(&value_2);
    int return_value = s21_is_less(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
  }

  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    set_scale(&value_2, 2);
    int return_value = s21_is_less(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
  }
}
END_TEST

START_TEST(s21_is_less_or_equal_test) {
  {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    int return_value = s21_is_less_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
  }

  {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    setsign(&value_1);
    int return_value = s21_is_less_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    setsign(&value_2);
    int return_value = s21_is_less_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
  }

  {
    s21_decimal value_1 = {{0, 0, 0, 0}};
    s21_decimal value_2 = {{0, 0, 0, 0}};
    setsign(&value_2);
    int return_value = s21_is_less_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    setsign(&value_1);
    setsign(&value_2);
    int return_value = s21_is_less_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
  }

  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    set_scale(&value_2, 2);
    int return_value = s21_is_less_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
  }

  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    int return_value = s21_is_less_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }
}
END_TEST

START_TEST(s21_is_greater_test) {
  {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    int return_value = s21_is_greater(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    setsign(&value_1);
    int return_value = s21_is_greater(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
  }

  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    setsign(&value_2);
    int return_value = s21_is_greater(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{0, 0, 0, 0}};
    s21_decimal value_2 = {{0, 0, 0, 0}};
    setsign(&value_2);
    int return_value = s21_is_greater(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
  }

  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    setsign(&value_1);
    setsign(&value_2);
    int return_value = s21_is_greater(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    set_scale(&value_2, 10);
    int return_value = s21_is_greater(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{234, 0, 0, 0}};
    s21_decimal value_2 = {{2, 0, 0, 0}};
    set_scale(&value_1, 2);
    int return_value = s21_is_greater(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }
}
END_TEST

START_TEST(s21_is_greater_or_equal_test) {
  {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    setsign(&value_1);
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
  }

  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    setsign(&value_2);
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{0, 0, 0, 0}};
    s21_decimal value_2 = {{0, 0, 0, 0}};
    setsign(&value_2);
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    setsign(&value_1);
    setsign(&value_2);
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    set_scale(&value_2, 2);
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }
}
END_TEST

START_TEST(s21_is_equal_test) {
  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
    int return_value = s21_is_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{123453u, 654u, 0xFFFFFFFF, 80000000}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
    int return_value = s21_is_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
  }

  {
    s21_decimal value_1 = {{0, 0, 0, 0}};
    s21_decimal value_2 = {{0, 0, 0, 0x80000000}};
    int return_value = s21_is_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{2, 0, 0, 0}};
    s21_decimal value_2 = {{20, 0, 0, 0}};
    set_scale(&value_2, 1);
    int return_value = s21_is_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }
}
END_TEST

START_TEST(s21_is_not_equal_test) {
  {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
    int return_value = s21_is_not_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
  }

  {
    s21_decimal value_1 = {{123453u, 654u, 0xFFFFFFFF, 80000000}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
    int return_value = s21_is_not_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
  }

  {
    s21_decimal value_1 = {{0, 0, 0, 80000000}};
    s21_decimal value_2 = {{0, 0, 0, 0}};
    int return_value = s21_is_not_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
  }
}
END_TEST

Suite *s21_comparison_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("S21 Comparison");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_is_less_test);
  tcase_add_test(tc_core, s21_is_less_or_equal_test);
  tcase_add_test(tc_core, s21_is_greater_test);
  tcase_add_test(tc_core, s21_is_greater_or_equal_test);
  tcase_add_test(tc_core, s21_is_equal_test);
  tcase_add_test(tc_core, s21_is_not_equal_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int test_comparison() {
  int no_failed = 0;
  Suite *s;
  SRunner *sr;

  s = s21_comparison_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return no_failed;
}