// ENCM 335 Fall 2021 Lab 4 Exercise D

#include <stdio.h>
#include <string.h>

int safecat(char *dest, const char* src, int dest_size);
// REQUIRES
//    dest_size > 0.
//    Array elements dest[0] ... dest[dest_size-1] exist.
//    dest points to the beginning of a C string with 
//    length < dest_size.
//    src points to the beginning of a C string.
// PROMISES
//    If the sum of the lengths of the two strings is less than
//    dest_size, the string in the dest array is the concatenation
//    of the original string in dest and the string from src, and
//    the return value is the length of the new string.
//
//    If not, the string in dest is the concatenation of the original
//    string in dest and as many characters from src as possible,
//    while leaving room for '\0' in dest[dest_size-1], and the return
//    value is -1.

int main(void)
{
  int rv;
  char buf[10];

  buf[0] = '\0';
  rv = safecat(buf, "", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"\" and 0).\n",
         buf, rv);
  rv = safecat(buf, "abcde", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"abcde\" and 5).\n", 
         buf, rv);
  rv = safecat(buf, "fghi", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"abcdefghi\" and 9).\n", 
         buf, rv);
  
  buf[0] = '\0';
  rv = safecat(buf, "jkl", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"jkl\" and 3).\n",
         buf, rv);
  rv = safecat(buf, "mnopqrs", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"jklmnopqr\" and -1).\n", 
         buf, rv);
  
  buf[0] = '\0';
  rv = safecat(buf, "01", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"01\" and 2).\n",
         buf, rv);
  rv = safecat(buf, "2345", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"012345\" and 6).\n",
         buf, rv);
  rv = safecat(buf, "6789ABCDEF", 10);
  printf("buf contains \"%s\" and rv is %d (expect \"012345678\" and -1).\n", 
         buf, rv);
  
  return 0;
}

int safecat(char *dest, const char* src, int dest_size)
{
  int i,j;
  
  if (strlen(dest)+strlen(src)<dest_size){
	  for(i=(strlen(dest)),j=0;j<strlen(src);i++,j++)
		  dest[i]=src[j];
	  dest[i]='\0';	
	  return strlen(dest);
  }
  else{
	  for(i=(strlen(dest)),j=0;i<dest_size-1;i++,j++)
		  dest[i]=src[j];
	  dest[i]='\0';	
	  return -1;
  }
}
