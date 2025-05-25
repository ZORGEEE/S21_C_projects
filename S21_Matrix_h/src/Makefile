CC= gcc
FLAG = -Wall -Wextra -Werror -std=c11 
UBUNTU_FLAGS = -lsubunit -lrt -lpthread -lm
LIBS = -lcheck
CFLAGS = -fprofile-arcs -ftest-coverage

TEST_FUNCS= ./tests/s21_unit_tests.c $(wildcard ./tests/test_functions/test_*.c)
MATRIX_FUNCS=$(wildcard ./functions/matrix_*.c)
OS=$(shell uname -s)

all: test

test:  s21_matrix.a $(TEST_FUNCS)
	$(CC) $(FLAG) -c $(TEST_FUNCS)
ifeq ($(OS), Darwin)
	$(CC) *.o -o unit_test $(LIBS) s21_matrix.a
else
	$(CC) *.o -o unit_test $(LIBS) $(UBUNTU_FLAGS) s21_matrix.a
endif
	rm -rf *.o
	./unit_test	

s21_matrix.a: $(MATRIX_FUNCS)
	$(CC) -c $(MATRIX_FUNCS)
	ar rc s21_matrix.a *.o

clang-fix:
	cp ../materials/linters/.clang-format .
	clang-format -i *.h ./functions/*.c ./tests/test_functions/*.c ./tests/*.c ./tests/*.h
	rm -rf .clang-format

gcov_report:
ifeq ($(OS), Darwin)
	$(CC) --coverage $(FLAG) $(TEST_FUNCS) $(MATRIX_FUNCS) -o gcov_test $(LIBS)
else
	$(CC) --coverage $(FLAG) $(TEST_FUNCS) $(MATRIX_FUNCS) -o gcov_test $(LIBS) $(UBUNTU_FLAGS)
endif
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info -c -d .
	genhtml -o report gcov_test.info
	open ./report/index.html
	rm -rf *.gc*

clean:
	rm -rf *.o unit_test s21_matrix.a gcov_test gcov_test.info *.gc* report
	
rebuild: clean test
