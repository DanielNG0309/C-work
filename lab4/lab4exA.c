// ENCM 335 Fall 2021 Lab 4 Exercise A

#include <stdio.h>

void copy_str(char *dest, const char *src);
// Like the C library function strcpy, but does not return a value.


int main(void)
{
  char foo[7];
  char bar[7] = {'E', 'F', 'G', 'H', 'I', 'J', 'K'};
  copy_str(bar, "ABCD");
  copy_str(foo, bar);
  return 0;
}


void copy_str(char *dest, const char *src)
{
  int i;
  for (i = 0; src[i] != '\0'; i++)
    dest[i] = src[i];

  // point one (this is after the for loop has finished)
  printf("%s",*dest);	
  dest[i] = '\0';
  return;
}
