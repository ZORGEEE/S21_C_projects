#include "tests.h"

START_TEST(s21_add_test) {
  {
    s21_decimal value_1 = {{13, 0, 0, 0}};
    set_scale(&value_1, 1);
    s21_decimal value_2 = {{286, 0, 0, 0}};
    set_scale(&value_2, 2);
    s21_decimal result;
    s21_decimal check = {{416, 0, 0, 0}};
    set_scale(&check, 2);
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    setsign(&value_2);
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{0, 0, 0, 0}};
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};
    set_scale(&value_1, 1);
    s21_decimal value_2 = {{2, 0, 0, 0}};
    set_scale(&value_2, 1);
    s21_decimal result;
    s21_decimal check = {{0x1, 0x0, 0x1, 0}};
    set_scale(&check, 1);
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{13, 0, 0, 0}};
    set_scale(&value_1, 2);
    s21_decimal value_2 = {{286, 0, 0, 0}};
    set_scale(&value_2, 1);
    s21_decimal result;
    s21_decimal check = {{2873, 0, 0, 0}};
    set_scale(&check, 2);
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{1, 0, 0, 0}};
    s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    set_scale(&value_2, 1);
    s21_decimal result;
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(return_value, 1);
  }

  {
    s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    set_scale(&value_1, 1);
    s21_decimal value_2 = {{1, 0, 0, 0}};
    s21_decimal result;
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(return_value, 1);
  }

  {
    s21_decimal value_1 = {{1, 0, 0, 0}};
    s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    s21_decimal result;
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(return_value, 1);
  }

  {
    s21_decimal value_1 = {{13, 0, 0, 0}};
    set_scale(&value_1, 2);
    setsign(&value_1);
    s21_decimal value_2 = {{286, 0, 0, 0}};
    set_scale(&value_2, 1);
    s21_decimal result;
    s21_decimal check = {{2847, 0, 0, 0}};
    set_scale(&check, 2);
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, 0);
  }

  {
    s21_decimal value_1 = {{13, 0, 0, 0}};
    set_scale(&value_1, 1);
    setsign(&value_1);
    s21_decimal value_2 = {{286, 0, 0, 0}};
    set_scale(&value_2, 2);
    setsign(&value_2);
    s21_decimal result;
    s21_decimal check = {{416, 0, 0, 0}};
    set_scale(&check, 2);
    setsign(&check);
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{1614, 0, 0, 0}};
    set_scale(&value_1, 3);
    s21_decimal value_2 = {{46071, 0, 0, 0}};
    set_scale(&value_2, 2);
    s21_decimal result;
    s21_decimal check = {{462324, 0, 0, 0}};
    set_scale(&check, 3);
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }
}
END_TEST

START_TEST(s21_sub_test) {
  {
    s21_decimal value_1 = {{13, 0, 0, 0}};
    set_scale(&value_1, 1);
    setsign(&value_1);
    s21_decimal value_2 = {{286, 0, 0, 0}};
    set_scale(&value_2, 2);
    setsign(&value_2);
    s21_decimal result;
    s21_decimal check = {{156, 0, 0, 0}};
    set_scale(&check, 2);
    int return_value = s21_sub(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{13, 0, 0, 0}};
    set_scale(&value_1, 1);
    setsign(&value_1);
    s21_decimal value_2 = {{286, 0, 0, 0}};
    set_scale(&value_2, 2);
    s21_decimal result;
    s21_decimal check = {{416, 0, 0, 0}};
    set_scale(&check, 2);
    setsign(&check);
    int return_value = s21_sub(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    setsign(&value_1);
    s21_decimal value_2 = {{2, 0, 0, 0}};
    s21_decimal result;
    int return_value = s21_sub(value_1, value_2, &result);
    ck_assert_int_eq(return_value, 2);
  }

  {
    s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    setsign(&value_1);
    s21_decimal value_2 = {{2, 0, 0, 0}};
    setsign(&value_2);
    s21_decimal result;
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(return_value, 2);
  }

  {
    s21_decimal value_1 = {{64071, 0, 0, 0}};
    set_scale(&value_1, 4);
    s21_decimal value_2 = {{5919, 0, 0, 0}};
    set_scale(&value_2, 1);
    s21_decimal result;
    s21_decimal check = {{5854929, 0, 0, 0}};
    set_scale(&check, 4);
    setsign(&check);
    int return_value = s21_sub(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }
}
END_TEST

START_TEST(s21_mul_test) {
  {
    s21_decimal value_1 = {{5, 0, 0, 0}};
    s21_decimal value_2 = {{7, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{35, 0, 0, 0}};
    int return_value = s21_mul(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 0}};
    s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{1, 0xFFFFFFFE, 0, 0}};
    int return_value = s21_mul(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{2, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    int return_value = s21_mul(value_1, value_2, &result);
    ck_assert_int_eq(return_value, 1);
  }

  {
    s21_decimal value_1 = {{123456u, 123u, 0, 0}};
    s21_decimal value_2 = {{654321u, 654u, 0, 0}};
    setsign(&value_2);
    set_scale(&value_1, 2);
    set_scale(&value_2, 3);
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{0xcedabe40, 0x99c0c5d, 0x13a3a, 0x80050000}};
    int return_value = s21_mul(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{2, 0, 0, 0}};
    setsign(&value_2);
    s21_decimal result = {{0, 0, 0, 0}};
    int return_value = s21_mul(value_1, value_2, &result);
    ck_assert_int_eq(return_value, N_INF);
  }

  {
    s21_decimal value_1 = {{17, 0, 0, 0}};
    setsign(&value_1);
    s21_decimal value_2 = {{0, 0, 0, 0}};
    s21_decimal result;
    s21_decimal check = {{0, 0, 0, 0}};
    int return_value = s21_mul(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }
}
END_TEST

START_TEST(s21_div_test) {
  {
    s21_decimal value_1 = {{35, 0, 0, 0}};
    s21_decimal value_2 = {{5, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{70, 0, 0, 0}};
    set_scale(&value_1, 1);
    set_scale(&value_2, 2);
    int return_value = s21_div(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{0x88888888, 0x88888888, 0x88888888, 0}};
    s21_decimal value_2 = {{0x2, 0, 0, 0}};
    setsign(&value_2);
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{0x44444444, 0x44444444, 0x44444444, 0}};
    setsign(&check);
    int return_value = s21_div(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{10, 0, 0, 0}};
    setsign(&value_1);
    s21_decimal value_2 = {{8, 0, 0, 0}};
    setsign(&value_2);
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{1, 0, 0, 0}};
    set_scale(&check, 0);
    int return_value = s21_div(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{15, 0, 0, 0}};
    setsign(&value_1);
    s21_decimal value_2 = {{0, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{0, 0, 0, 0}};
    int return_value = s21_div(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, N_NAN);
  }

  {
    s21_decimal value_1 = {{10, 0, 0, 0}};
    s21_decimal value_2 = {{1, 0, 0, 0}};
    set_scale(&value_2, 2);
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{1000u, 0, 0, 0}};
    int return_value = s21_div(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }
}
END_TEST

START_TEST(s21_mod_test) {
  {
    s21_decimal value_1 = {{46, 0, 0, 0}};
    set_scale(&value_1, 1);
    s21_decimal value_2 = {{123, 0, 0, 0}};
    set_scale(&value_2, 2);
    s21_decimal check = {{91, 0, 0, 0}};
    set_scale(&check, 2);
    s21_decimal result;
    int return_value = s21_mod(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{46, 0, 0, 0}};
    set_scale(&value_1, 1);
    s21_decimal value_2 = {{0, 0, 0, 0}};
    set_scale(&value_2, 2);
    s21_decimal result;
    int return_value = s21_mod(value_1, value_2, &result);
    ck_assert_int_eq(return_value, N_NAN);
  }

  {
    s21_decimal value_1 = {{46, 0, 0, 0}};
    set_scale(&value_1, 1);
    s21_decimal value_2 = {{123, 0, 0, 0}};
    set_scale(&value_2, 2);
    setsign(&value_2);
    s21_decimal check = {{91, 0, 0, 0}};
    set_scale(&check, 2);
    s21_decimal result;
    int return_value = s21_mod(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{46, 0, 0, 0}};
    set_scale(&value_1, 1);
    setsign(&value_1);
    s21_decimal value_2 = {{123, 0, 0, 0}};
    set_scale(&value_2, 2);
    s21_decimal check = {{91, 0, 0, 0}};
    set_scale(&check, 2);
    setsign(&check);
    s21_decimal result;
    int return_value = s21_mod(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }

  {
    s21_decimal value_1 = {{46, 0, 0, 0}};
    set_scale(&value_1, 1);
    setsign(&value_1);
    s21_decimal value_2 = {{123, 0, 0, 0}};
    set_scale(&value_2, 2);
    setsign(&value_2);
    s21_decimal check = {{91, 0, 0, 0}};
    set_scale(&check, 2);
    setsign(&check);
    s21_decimal result;
    int return_value = s21_mod(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
  }
}
END_TEST

Suite *s21_arithmetic_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("S21 Arithmetic");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, s21_add_test);
  tcase_add_test(tc_core, s21_sub_test);
  tcase_add_test(tc_core, s21_mul_test);
  tcase_add_test(tc_core, s21_div_test);
  tcase_add_test(tc_core, s21_mod_test);
  suite_add_tcase(s, tc_core);

  return s;
}

int test_arithmetic() {
  int no_failed = 0;
  Suite *s;
  SRunner *sr;

  s = s21_arithmetic_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  no_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return no_failed;
}