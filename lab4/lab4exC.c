// ENCM 335 Fall 2021 Lab 4 Exercise C

#include <stdio.h>

int main(void)
{
  char buffer[80];   // enough space for a string of length <= 79

  // THIS IS A GOOD WAY TO LEARN SOMETHING ABOUT C STRINGS, BUT IT'S
  // NOT A GOOD EXAMPLE OF READABLE OR PRACTICAL CODE! 

  // Put characters into the string using ASCII codes.
  buffer[0] = 73;
  buffer[1] = 110;
  buffer[2] = 32;
  buffer[3] = 67;
  buffer[4] = 32;
  buffer[5] = 116;
  buffer[6] = 104;
  buffer[7] = 101;
  buffer[8] = 32;
  buffer[9] = 118;
  buffer[10] = 97;
  buffer[11] = 108;
  buffer[12] = 117;
  buffer[13] = 101;
  buffer[14] = 32;
  buffer[15] = 111;
  buffer[16] = 102;
  buffer[17] = 32;
  buffer[18] = 57;
  buffer[19] = 32;
  buffer[20] = 42;
  buffer[21] = 32;
  buffer[22] = 55;
  buffer[23] = 32;
  buffer[24] = 37;
  buffer[25] = 32;
  buffer[26] = 49;
  buffer[27] = 49;
  buffer[28] = 32;
  buffer[29] = 105;
  buffer[30] = 115;
  buffer[31] = 32;
  buffer[32] = 56;
  buffer[33] = 46;
  // Put the end-of-string character at the end of the string.
  buffer[34] = 0;

  printf("The string in buffer is \"%s\"\n", buffer);
  return 0;
}
