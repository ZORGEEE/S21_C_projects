#include "tests.h"

START_TEST(s21_floor_test) {
  {
    s21_decimal value_1 = {{7444923, 0, 0, 0}};
    set_scale(&value_1, 5);
    s21_decimal check = {{74, 0, 0, 0}};
    s21_decimal result;
    int return_value = s21_floor(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{7444923, 0, 0, 0}};
    set_scale(&value_1, 5);
    setsign(&value_1);
    s21_decimal check = {{75, 0, 0, 0}};
    setsign(&check);
    s21_decimal result;
    int return_value = s21_floor(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }
}
END_TEST

START_TEST(s21_round_test) {
  {
    s21_decimal value_1 = {{7464923, 0, 0, 0}};
    set_scale(&value_1, 5);
    s21_decimal check = {{75, 0, 0, 0}};
    s21_decimal result;
    int return_value = s21_round(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{7444923, 0, 0, 0}};
    set_scale(&value_1, 5);
    s21_decimal check = {{74, 0, 0, 0}};
    s21_decimal result;
    int return_value = s21_round(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{7464923, 0, 0, 0}};
    setsign(&value_1);
    set_scale(&value_1, 5);
    s21_decimal check = {{75, 0, 0, 0}};
    setsign(&check);
    s21_decimal result;
    int return_value = s21_round(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{7444923, 0, 0, 0}};
    setsign(&value_1);
    set_scale(&value_1, 5);
    s21_decimal check = {{74, 0, 0, 0}};
    setsign(&check);
    s21_decimal result;
    int return_value = s21_round(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }
}
END_TEST

START_TEST(s21_truncate_test) {
  {
    s21_decimal value_1 = {{35, 0, 0, 0}};
    s21_decimal check = {{3, 0, 0, 0}};
    set_scale(&value_1, 1);
    s21_truncate(value_1, &value_1);
    ck_assert_int_eq(s21_is_equal(value_1, check), 1);
  }

  {
    s21_decimal value_1 = {{123456, 0, 0, 0}};
    set_scale(&value_1, 3);
    setsign(&value_1);
    s21_decimal check = {{123, 0, 0, 0}};
    setsign(&check);
    s21_truncate(value_1, &value_1);
    ck_assert_int_eq(s21_is_equal(value_1, check), 1);
  }
}
END_TEST

START_TEST(s21_negate_test) {
  {
    s21_decimal value_1 = {{5, 0xFFFFFFFF, 0, 0}};
    setsign(&value_1);
    s21_decimal check = {{5, 0xFFFFFFFF, 0, 0}};
    s21_decimal result;
    int return_value = s21_negate(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{1, 1, 1, 0}};
    s21_decimal check = {{1, 1, 1, 0x80000000}};
    s21_decimal result;
    int return_value = s21_negate(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }
}
END_TEST

Suite *s21_other_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("S21 Other");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_floor_test);
  tcase_add_test(tc_core, s21_round_test);
  tcase_add_test(tc_core, s21_truncate_test);
  tcase_add_test(tc_core, s21_negate_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int test_other() {
  int no_failed = 0;
  Suite *s;
  SRunner *sr;

  s = s21_other_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return no_failed;
}
