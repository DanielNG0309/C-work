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
// REQUIRES 
//   s points to the start of an array of at least size bytes.
//   stream is open for input.
// PROMISES
//   Reverse all values of the input string
 
int main(void)
{
  char line[LINE_ARRAY_SIZE];
  int end_line;
  
  while (1){
	  printf("Please enter a line of text. To quit, start it with %c.\n",
           QUIT_LETTER);
      end_line = get_a_line(line,LINE_ARRAY_SIZE,stdin);
      if (line[0] == QUIT_LETTER)
		  break;
	  if (end_line<LINE_ARRAY_SIZE-1){
		  printf("The line, newline removed, was \"%s\".", line);
		  reverse(line);
		  printf("  In reverse, that is \"%s\".\n", line);
	  }
	  else if(end_line >= LINE_ARRAY_SIZE - 1){
		  fputs("Input line ignored because it was too long!\n", stdout);
		  eat_til_newline(stdin);
	  }
  }

  fputs("\nReason for quitting: ", stdout);
  if (end_line==EOF)
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
  int i,len,holder;
  len=strlen(s);
  for (i=0;i<len/2;i++){
	  holder=s[i];
	  s[i]=s[len-i-1];
	  s[len-i-1]=holder;
  }
}
int get_a_line(char *s, int size, FILE *stream){
  int i; 
  for (i=0;i<size-1;i++){
	  s[i]=fgetc(stream);
	  if (s[i]==EOF)
		  return EOF;
	  if (s[i]=='\n')
		  break;
	  
  }
	  s[i]='\0';
	   
  return i;
}
