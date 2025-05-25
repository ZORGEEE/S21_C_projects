#ifndef S21_GREP_H
#define S21_GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arguments {
  _Bool e;
  _Bool i;
  _Bool v;
  _Bool c;
  _Bool l;
  _Bool n;
  _Bool h;
  _Bool s;
  _Bool f;
  _Bool o;
  int wrong;
  char *pattern;
} arguments;

void parser(int argc, char **argv, arguments *arg);
void outline(char *filename, arguments *arg, int f_count);
void print_line(int f_count, arguments *arg, char *filename, int num,
                char *line);
void print_sum(char *filename, int f_count, int count, arguments *arg);
void add_pattern(arguments *arg, char *new_pattern);
void f_flag(arguments *arg, char *new_file);
void error_file(char *filename);
void error_pattern(char *pattern);
void error_mem();

#endif