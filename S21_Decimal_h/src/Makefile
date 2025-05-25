.PHONY: s21_decimal.a

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror
TESTFLAGS = -lcheck -coverage -lpthread -pthread -L.

C_FILES = s21_*.c help.c
O_FILES = s21_*.o help.o

all:
	$(MAKE) s21_decimal.a

s21_decimal.a:
	$(MAKE) clean
	$(CC) $(CFLAGS) -c $(C_FILES)
	ar rcs s21_decimal.a $(O_FILES)

test:
	$(CC) $(CFLAGS) $(TESTFLAGS) run_tests.c tests/*.c s21_decimal.a -o test_s21_decimal
	./test_s21_decimal

gcov_report:
	$(CC) $(CFLAGS) $(TESTFLAGS) $(C_FILES) run_tests.c tests/*.c -o gcov_report
	./gcov_report
	lcov -t "gcovreport" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info
	rm -f *.info
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.o

clean:
	rm -f *.a
	rm -f *.o
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.gcov
	rm -f *.info
	rm -f test_s21_decimal
	rm -f gcov_report
	rm -rf report