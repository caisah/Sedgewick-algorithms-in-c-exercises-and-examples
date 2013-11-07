#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "stacks.h"

/* Transforms infix expression to postfix notation
   Evaluates resulting postfix expression */
int main(void) 
{
  char *a1 = "(4 + 2)", *a2;
  int i, j = 0, n1 = strlen(a1), n2;
  char *st1;
  int *st2;

  st1 = cSTACKinit(n1);
  a2 = malloc(n1 * sizeof(int));
  for (i = 0; i < n1; i++)
    {
      if (a1[i] == ')')
	{
	  a2[j++] = cSTACKpop(st1);
	  a2[j++] = ' ';
	}
      if ((a1[i] == '+') || (a1[i] == '*'))
	cSTACKpush(st1, a1[i]);
      while ((a1[i] >= '0') && (a1[i] <= '9'))
	a2[j++] = a1[i++];
      if ((a1[i-1] >= '0') && (a1[i-1] <= '9'))
	a2[j++] = ' ';
    }
  while (!cSTACKempty())
    a2[j++] = cSTACKpop(st1);
  n2 = j;
  // print suffix expression
  for (i = 0; i < n2; i++)
    printf("%c", a2[i]);
  printf("\n");
  // evaluate
  st2 = iSTACKinit(n2);
  for (i = 0; i < n2; i++)
    {
      if (a2[i] == '+')
  	iSTACKpush(st2, iSTACKpop(st2) + iSTACKpop(st2));
      if (a2[i] == '*')
  	iSTACKpush(st2, iSTACKpop(st2) * iSTACKpop(st2));
      if ((a2[i] >= '0') && (a2[i] <= '9'))
  	iSTACKpush(st2, 0);
      while ((a2[i] >= '0') && (a2[i] <= '9'))
  	iSTACKpush(st2, 10 * iSTACKpop(st2) + (a2[i++] - '0'));
    }
  printf("%d \n", iSTACKpop(st2));
  return 0;
}
