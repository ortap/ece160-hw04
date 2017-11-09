#include <stdio.h>
#include <stdlib.h>

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2,
  YEARS_LEFT_AND_NAME = 3,
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  char *year;
} Student;

void print_student(Mode m, Student s){
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name);
      break;
    case MAJOR_AND_NAME:
      printf("%s %s %s\n", s.major, s.first_name, s.last_name);
      break;
    case YEAR_AND_NAME:
      printf("%s %s %s\n", s.year, s.first_name, s.last_name);
      break;
    case YEARS_LEFT_AND_NAME: 
      printf("%d %s %s\n", (atoi(s.year)-2017), s.first_name, s.last_name);
      break;
  }
}

/*
	argv[1] will be the Mode integer
	argv[2...] will be student info in the form [first_name, last_name, major, year]
	the fields are all strings (char[])
	except year is a number (int)
*/
void main(int argc, char *argv[]) {
  // TODO: parse argv to populate student structs 
  // for now, here's two hardcoded students:
  // Declarations

  //open the input file
  char *filename = argv[1];
  FILE *fp = fopen(filename, "r");

  if(fp == NULL){
      printf("Error: Unable to locate or open file: %s\n", filename);
    }

  
  char *buffer = malloc(256);
  Student array[256];
  Student sx;
  int i = 0;
  while((fgets(buffer,255,fp)) != NULL){
    sx.first_name = malloc(256);
    sx.last_name = malloc(256);
    sx.major = malloc(256);
    sx.year = malloc(256);
    sscanf(buffer, "%s %s %s %s", sx.first_name, sx.last_name, sx.major, sx.year);
    array[i] = sx;
    i++;
  }

  int si, bin;
  while(fgets(buffer,255,stdin))
    {
      if(sscanf(buffer, "%d %d\n", &si, &bin) == 2)
	{
	  Mode m = bin;
	  if(m>3 || m < 0)
	    printf("Error: Invalid Mode\n");
	  else
	    print_student(m,array[si]);
	}
      else
	printf("Error:Invalid Input\n");
    }
}
