// longest_run9D2.c
// ENCM 335 Fall 2021 Lab 10 Exercise A Part II

#include <stdio.h>

void longest_run(const char *s, const char **begin, const char **end)
{
  *begin = s;
  *end = s;
  int length, max_length = 0;
  const char *t;
  while (*s != '\0') {
    t = s + 1;
    while (*s == *t) {
      t++;
    }
    length = t - s;
    printf("length is %d\n",length);
    // point one

    if (length > max_length) {
      *begin = s;
      *end = t;
      max_length = length;
    }
    s = t;
  }  
}

int main(void)
{
  const char *b, *e;
  longest_run("AAAbbccDDDDee", &b, &e);
  while (b != e) {
    fputc(*b, stdout);
    b++;
  }
  fputc('\n', stdout);
  return 0;
}
