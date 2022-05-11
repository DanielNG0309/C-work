// grades7C.c
// ENCM 335 Fall 2021 Lab 7 Exercise C

#include <stdio.h>
#include <string.h>

#define NUM_OF_ASSIGNMENTS 10

struct mark_record {
  char last_name[8];  // way too short for practical use!
  char initials[4];
  int id_number;
  double mark[NUM_OF_ASSIGNMENTS];
};

typedef struct mark_record mark_record_t;

void list_students(const mark_record_t *record, int n);
// REQUIRES: 
//   n >= 1.
//   Elements record[0] ... record[n-1] exist and have valid
//   data in their last name, initials, and id_number members.
// PROMISES:
//   Students' names and ID numbers are printed, one line per student,
//   in this format:
//   last_name, initials     id_number

void list_assignment_totals(const mark_record_t *record, 
			    int n,
			    const double *maxes);
// REQUIRES: 
//   n >= 1.
//   Elements record[0] ... record[n-1] exist, have valid
//   data in their last name, initials, and id_number members,
//   and valid marks in their marks arrays.
// PROMISES:
//   Students' names, ID numbers, and overall assignment scores
//   are printed, one per line, in the format given in the Lab 5
//   Exercise D instructions.

int main(void)
{
  // It would make sense to read scores and maximum score data from
  // an input file, but we don't know how to do that yet in ENCM 335
  // this term.  So we'll just put test data directly into a local
  // variable in main.
  mark_record_t test_scores[ ] = {
    { 
      "Cross", "JP", 900431,
      {8.5,  8.0, 11.0,  8.5,  8.0, 11.0,  8.5,  7.0, 11.5,  7.5}
    },
    { 
      "Dodd", "AJ", 900872,
      {8.5,  8.5, 10.5,  9.0, -1.0,  9.5,  9.5,  7.0, 12.0,  5.0}
    },
    { 
      "Moss", "WLM", 901203,
      {7.5, 10.0, 12.0,  8.5,  7.0, 11.0, 10.0, -1.0, 13.0, -1.0}
    },
    { 
      "Ross", "T", 900398,
      {7.5,  -1.0, 11.0,  8.5,  7.0, 12.0,  9.0, -1.0, 12.5,  8.0}
    },
    { 
      "Todd", "BL", 901197,
      {9.0,  8.0, -1.0,  6.0,  8.0,  9.5, 11.0, 10.0, -1.0,  6.0}
    }
  };

  // Change the next line to #if 1 as part of solving the problem. 
#if 1
  double max_scores[ ] = {
    10.0, 10.0, 12.0, 9.0, 10.0, 12.0, 11.0, 10.0, 13.0, 8.0
  };
#endif

  // Replace this call with a call to list_assignment_totals.
  list_assignment_totals(test_scores, sizeof(test_scores) / sizeof(mark_record_t), max_scores);

  return 0;
}

void list_students(const mark_record_t *record, int n)
{
  int i;
  char name[20];
  for (i = 0; i < n; i++) {
    strcpy(name, record[i].last_name);
    strcat(name, ", ");
    strcat(name, record[i].initials);
    printf("%-15s %6d\n", name, record[i].id_number);
  }
}

// Insert a definition for list_assignment_totals here.
void list_assignment_totals(const mark_record_t *record,int n,const double *maxes){
  int i,j;
  double total_weights,total_marks;
  char name[20];
  for (i=0;i<n;i++){
	  total_weights=0.0;
	  total_marks=0.0;
	  
	  strcpy(name, record[i].last_name);
      strcat(name, ", ");
      strcat(name, record[i].initials);
      
      for (j=0;j<NUM_OF_ASSIGNMENTS;j++){
		  if (record[i].mark[j] != -1.0){
			  total_weights += maxes[j];
			  total_marks += record[i].mark[j];
		  }
	  }
	 //print out the formatted data 
	 printf("%-15s %6d    %5.1f / %5.1f, %.2f%%\n",name,record[i].id_number,
	 total_marks,total_weights,total_marks/total_weights*100);
  }	
}
