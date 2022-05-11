// charIO4C.c
// ENCM 335 Fall 2021 Lab 6 Exercise C

#include <stdio.h>
#include <ctype.h>

#define QUIT_LETTER 'q'

int main(void)
{
  int c, line_length,num_letters,num_digits;

  // Each pass through the outer loop reads a line of input.
  while (1) {
    printf("\nEnter a line of text. (To quit, start the line with %c.)\n",
	   QUIT_LETTER);
    c = fgetc(stdin);
    if (c == EOF || c == QUIT_LETTER)
      break;			// Leave outer loop.

    line_length = 0;
    num_letters=0;
    num_digits=0;
    printf("Changing uppercase to lowercase ...\n");

    // Inner loop reads chars until '\n' or EOF is found.
    while (c != '\n' && c != EOF) {
      line_length++;
      if (isalpha(c))
		  num_letters++;
	  else if (isdigit(c))
		  num_digits++;
      fputc(tolower(c), stdout);
      c = fgetc(stdin);
    }
    fputc('\n', stdout);
    printf("Length of line, not counting '\\n', was %d.\n", line_length);
    printf("%d of the characters in the line were letters.\n",num_letters);
    printf("%d of the characters in the line were digits.\n",num_digits);
  }

  printf("Bye!\n");
  return 0;
}
