#ifndef S21_CAT_H
#define S21_CAT_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct arguments {
  _Bool b;
  _Bool s;
  _Bool n;
  _Bool e;
  _Bool E;
  _Bool t;
  _Bool T;
  _Bool v;
} arguments;

arguments parser(int argc, char **argv);
void output(char *filename, arguments *arg);
void number_func(char *line, int *line_count, arguments *arg);
void e_and_t_func(char *line, arguments *arg);
void s_func(char *line, int *empty_count);
// char v_output(char ch);
void error_opt();
void error_file(char *filename);
void error_mem();

#endif