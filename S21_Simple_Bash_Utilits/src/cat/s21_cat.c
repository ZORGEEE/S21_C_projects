#include "s21_cat.h"

int main(int argc, char **argv) {
  arguments arg = parser(argc, argv);

  while (optind < argc) {
    output(argv[optind], &arg);
    optind++;
  }
  return 0;
}

arguments parser(int argc, char **argv) {
  arguments arg = {0};
  int opt;
  struct option long_options[] = {{"number-nonblank", no_argument, NULL, 'b'},
                                  {"number", no_argument, NULL, 'n'},
                                  {"squeeze-blank", no_argument, NULL, 's'},
                                  {0, 0, 0, 0}};
  opt = getopt_long(argc, argv, ":beEnstTv", long_options, 0);
  switch (opt) {
    case 'b':
      arg.b = 1;
      break;
    case 'e':
      arg.e = 1;
      arg.v = 1;
      break;
    case 'E':
      arg.e = 1;
      break;
    case 'n':
      arg.n = 1;
      break;
    case 's':
      arg.s = 1;
      break;
    case 't':
      arg.t = 1;
      arg.v = 1;
      break;
    case 'T':
      arg.t = 1;
      break;
    case 'v':
      arg.v = 1;
      break;
    case '?':
      error_opt();
    default:
      break;
  }
  return arg;
}

void output(char *filename, arguments *arg) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    error_file(filename);
  }
  int read = 0;
  char *line = NULL;
  size_t memline = 0;
  int line_count = 1;
  int empty_count = 0;
  read = getline(&line, &memline, f);
  while (read != -1) {
    if (line == NULL) {
      error_mem();
    } else if (arg->b || arg->n) {
      number_func(line, &line_count, arg);
    } else if (arg->e || arg->t) {
      e_and_t_func(line, arg);
    } else if (arg->s) {
      s_func(line, &empty_count);
    } else if (!(arg->b || arg->e || arg->n || arg->s || arg->t)) {
      printf("%s", line);
    }
    read = getline(&line, &memline, f);
  }
  fclose(f);
  free(line);
}

void number_func(char *line, int *line_count, arguments *arg) {
  if (line[0] != '\n' || arg->n) {
    printf("%6d\t%s", *line_count, line);
    (*line_count)++;
  } else {
    printf("%s", line);
  }
}

void e_and_t_func(char *line, arguments *arg) {
  unsigned char ch;
  int i = 0;
  while ((ch = line[i]) != '\0') {
    i++;
    if (ch == '\n' && arg->e) {
      printf("$\n");
      continue;
    }
    if (ch == '\t' && arg->t) {
      printf("^I");
      continue;
    }
    if (arg->v) {
      if ((ch != 9 && ch != 10 && ch < 32) || ch == 127) {
        if (ch == 127) {
          ch = '?';
        }
        ch += 64;
        printf("^%c", ch);
      } else if (ch >= 128 && ch < 160) {
        printf("M-^%c", ch - 64);
      } else {
        putchar(ch);
      }
      continue;
    }
    putchar(ch);
  }
}

void s_func(char *line, int *empty_count) {
  if (line[0] == '\n') {
    (*empty_count)++;
    if ((*empty_count) <= 1) {
      printf("%s", line);
    }
  } else {
    printf("%s", line);
    (*empty_count) = 0;
  }
}

void error_opt() {
  printf("s21_cat: illegal option\nusage: s21_cat [-b -e -n -s -t]");
  exit(1);
}

void error_file(char *filename) {
  printf("s21_cat: %s: No such file or directory\n", filename);
}

void error_mem() {
  printf("UNABLE TO ALLOCATE MEMORY\n");
  exit(1);
}