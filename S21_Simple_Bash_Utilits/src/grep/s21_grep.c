#include "s21_grep.h"

int main(int argc, char *argv[]) {
  arguments arg = {0};
  parser(argc, argv, &arg);

  if (!arg.f && !arg.e) {
    add_pattern(&arg, argv[optind]);
    optind++;
  }

  if (arg.pattern == NULL || arg.wrong == '?') {
    error_pattern(arg.pattern);
  }

  if (arg.pattern[strlen(arg.pattern) - 1] == '|') {
    arg.pattern[strlen(arg.pattern) - 1] = '\0';
  }

  int f_count = argc - optind;

  while (optind < argc && arg.pattern != NULL) {
    outline(argv[optind], &arg, f_count);
    optind++;
  }

  if (arg.pattern != NULL) {
    free(arg.pattern);
  }

  return 0;
}

void outline(char *filename, arguments *arg, int f_count) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    if (!arg->s) {
      error_file(filename);
    }
    return;
  }

  regex_t reg;
  regmatch_t begin;
  char *line = NULL;
  size_t len = 0;
  int match, cflag = 0;
  if (arg->i) {
    cflag = (REG_EXTENDED | REG_ICASE);
  } else {
    cflag = REG_EXTENDED;
  }
  int count = 0, num = 0;
  regcomp(&reg, arg->pattern, cflag);

  while (getline(&line, &len, f) != -1) {
    num++;
    match = regexec(&reg, line, 1, &begin, 0);
    if (arg->v) match = !match;
    if (!match) {
      count++;
      print_line(f_count, arg, filename, num, line);
    }
  }
  print_sum(filename, f_count, count, arg);

  fclose(f);
  free(line);
  regfree(&reg);
}

void print_line(int f_count, arguments *arg, char *filename, int num,
                char *line) {
  if (arg->c || arg->l) {
    return;
  }

  if (f_count > 1 && !arg->h) printf("%s:", filename);
  if (arg->n) {
    printf("%d:%s", num, line);
  } else {
    printf("%s", line);
  }

  if (line[strlen(line) - 1] != '\n') {
    printf("\n");
  }
}

void print_sum(char *filename, int f_count, int count, arguments *arg) {
  if (arg->c) {
    if (arg->l && count > 1) {
      count = 1;
    }
    if (f_count > 1 && !arg->h) {
      printf("%s:", filename);
    }
    printf("%d\n", count);
  }
  if (arg->l && count > 0) {
    printf("%s\n", filename);
  }
}

void parser(int argc, char **argv, arguments *arg) {
  int opt;
  while ((opt = getopt_long(argc, argv, ":e:ivclnhsf:o", NULL, 0)) != -1) {
    switch (opt) {
      case 'e':
        arg->e = 1;
        add_pattern(arg, optarg);
        break;
      case 'f':
        arg->f = 1;
        f_flag(arg, optarg);
        break;
      case 'i':
        arg->i = 1;
        break;
      case 'v':
        arg->v = 1;
        break;
      case 'c':
        arg->c = 1;
        break;
      case 'l':
        arg->l = 1;
        break;
      case 'n':
        arg->n = 1;
        break;
      case 'h':
        arg->h = 1;
        break;
      case 's':
        arg->s = 1;
        break;
      case 'o':
        arg->o = 1;
        break;
      default:
        if (arg->wrong == 0) {
          arg->wrong = opt;
        }
    }
  }
}

void add_pattern(arguments *arg, char *new_pattern) {
  if (arg->pattern == NULL) {
    arg->pattern = (char *)malloc(strlen(new_pattern) + 2);
    if (arg->pattern == NULL) {
      error_mem();
    }
    strcpy(arg->pattern, new_pattern);
    strcat(arg->pattern, "|");
  } else {
    arg->pattern = (char *)realloc(
        arg->pattern, strlen(arg->pattern) + strlen(new_pattern) + 2);
    if (arg->pattern == NULL) {
      error_mem();
    }
    strcat(arg->pattern, new_pattern);
    strcat(arg->pattern, "|");
  }
}

void f_flag(arguments *arg, char *new_file) {
  FILE *f = fopen(new_file, "r");
  char *line = NULL;
  size_t len = 0;

  if (f == NULL) {
    error_file(new_file);
    exit(1);
  }
  int get = getline(&line, &len, f);
  while (get != -1) {
    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';
    }
    add_pattern(arg, line);
    get = getline(&line, &len, f);
  }
  fclose(f);

  if (line) {
    free(line);
  }
}

void error_file(char *filename) {
  printf("s21_grep: %s: No such file or directory\n", filename);
}

void error_pattern(char *pattern) {
  if (pattern != NULL) {
    printf(
        "s21_grep: invalid option\nusage: s21_grep [-ivclnhso] [-e pattern]"
        "[-f file] [pattern] [file ...]\n");
  }
  exit(1);
}

void error_mem() {
  printf("UNABLE TO ALLOCATE MEMORY\n");
  exit(1);
}