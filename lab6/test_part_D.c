// line-getter6D.c
// ENCM 335 Fall 2021 Lab 6 Exercise D

#include <stdio.h>
#include <string.h>

#define QUIT_LETTER 'q'

// Again, in a practical program, this is a ridiculously small size
// for an array that is supposed to hold a line of text. But it's
// convenient for testing purposes.
#define LINE_ARRAY_SIZE 10

int eat_til_newline(FILE *stream);
// REQUIRES: stream is open for input.
// PROMISES: Characters are read from stream and discarded until either a
//   '\n' has been read or an input error has occurred.
//   Return value is 0 if '\n' is read, and EOF for an error.

int get_a_line(char *s, int size, FILE *stream);
// Does what fgets does, using repeated calls to fgetc, but
// provides a more useful return value than fgets does.
//
// REQUIRES
//   size > 1. 
//   s points to the start of an array of at least size bytes.
//   stream is open for input.
// PROMISES
//   Return value is EOF if input error occurred.
//   Otherwise, return value gives the index of the '\0' that
//   terminates the string in the array.

void reverse(char *s);

int main(void)
{
  char line[LINE_ARRAY_SIZE];
  int input_error = 0, len;

  while (1) {
    printf("Please enter a line of text. To quit, start it with %c.\n",
           QUIT_LETTER);
    
    if (NULL == fgets(line, LINE_ARRAY_SIZE, stdin)) { 
      // Case 4.  fgets did not read even one char succesfully.
      input_error = 1;
      break;
    }
    if (line[0] == QUIT_LETTER)
      break;

    // Find out what fgets actually did, and react accordingly.
    len = strlen(line);
    if (line[len - 1] == '\n') { // Case 1: Yay! We read a complete line!
      line[len - 1] = '\0';      // Write '\0' over '\n'.
      printf("The line, newline removed, was \"%s\".", line);
      reverse(line);
      printf("  In reverse, that is \"%s\".\n", line);
    }
    else if (len == LINE_ARRAY_SIZE - 1) { // Case 2: Too much input.
      eat_til_newline(stdin);
      fputs("Input line ignored because it was too long!\n", stdout);
    }
    else {                   // Case 3: Error after reading one or more chars.
      input_error = 1;
      break;
    }
  } // while (1)

  fputs("\nReason for quitting: ", stdout);
  if (input_error)
    fputs("unexpected input error.\n", stdout);
  else
    printf("found %c at beginning of line.\n", QUIT_LETTER);

  return 0;
}

int eat_til_newline(FILE * stream)
{
  int c;
  do {
    c = fgetc(stream);
  } while (c != EOF && c != '\n');
  
  // Return EOF if c == EOF, otherwise return 0.
  return (c == EOF) ? EOF : 0;
}

void reverse(char *s)
{
  // You need to add some code here!
}
