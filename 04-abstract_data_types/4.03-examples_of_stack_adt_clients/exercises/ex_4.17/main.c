#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

#define MAXLEN 100
#define MAXLINES 10

/* narray struct containing an array of strings
   and the length of the array */
typedef struct
{
  char **arr;
  int n;
} n_array;

/* read_lines: reads lines into an array of strings (n_array)
   returns the n_array */
n_array read_lines(void)
{
  n_array t;
  char c, *temp;
  int i = 0, j = 0;

  t.n = 0;
  t.arr = malloc(MAXLINES * sizeof(char*));
  temp = malloc(MAXLEN * sizeof(char));
  while ( (c = getchar()) != EOF)
    {
      if (c == '\n')
	{
	  temp[i] = '\0';                      // mark end of string
	  t.arr[j] = malloc(i * sizeof(char));
	  strcpy(t.arr[j], temp);              // copy temp to array
	  free(temp);                          // clean temp
	  temp = malloc(MAXLEN * sizeof(char));
	  t.n++;
	  j++;
	  if (MAXLINES == j)  	               // realloc in case more lines are entered
	    t.arr[j] = realloc(t.arr[j], (MAXLINES + i) * sizeof(char*));
	  i = 0;
	}
      else
	temp[i++] = c;                         // add char to temp
      if (i == MAXLEN)                         // realloc in case more chars are entered
	temp = realloc(temp, (i + MAXLINES));
    }
  temp[i] = '\0';                              // last line
  t.arr[j] = malloc(i * sizeof(char));
  strcpy(t.arr[j], temp);
  free(temp);
  return t;
}

int main(void) 
{
  n_array t;
  int i, j, m;
  char *a, *vars;
  c_link op_stack;
  i_link num_stack;
  
  printf("Enter those lines:\n");
  t = read_lines();
  cSTACKinit();
  iSTACKinit();
  for (i = 0; i < t.n; i++)
    {
      a = t.arr[i];
      m = strlen(a);
      for (j = 0; j < m; j++)
	{
	    
	  
	}
    }
  /* printf("Enter the seize of stack: "); */
  /* scanf("%d", &n); */
  /* STACKinit(n); */
  /* STACKpush(1); */
  /* STACKpush(2); */
  /* printf("%d, %d\n", STACKpop(), STACKpop()); */
  /* printf("Stack empty? %d\n", STACKempty()); */
  return 0;
}
