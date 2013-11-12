#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "item.h"
#include "stack.h"

int evaluate(char*);

/* evaluates infix expressions containing + and * signs
   and one digit numbers */
int main(void) 
{
  char *a = "(4 * (2 + 3))";

  printf("The result: %d\n", evaluate(a));
  return 0;
}

/* evaluate: transforms infix expression into sufix expression
             evaluates the resulting expression; returns result */
int evaluate(char *expr)
{
  char a;
  int n, i;

  n = strlen(expr);
  STACKinit(n);
  // transfrorm infix to sufix using 2 stacks
  for (i = 0; i < n; i++)
    {
      if (expr[i] == ')')
	endSTACKpush(beginSTACKpop());
      if ((expr[i] == '+') || (expr[i] == '*'))
	beginSTACKpush(expr[i]);
      if ((expr[i] >= '0') && (expr[i] <= '9'))
	endSTACKpush(expr[i]);
    }
  // copy to the other stuck to get correct order
  while (!endSTACKempty())
    beginSTACKpush(endSTACKpop());
  // evaluate sufix expression using another int stack
  iSTACKinit(n);
  while (!beginSTACKempty())
    {
      a = beginSTACKpop();
      if (a == '+')
	iSTACKpush(iSTACKpop() + iSTACKpop());
      if (a == '*')
	iSTACKpush(iSTACKpop() * iSTACKpop());
      if ( (a > '0') && (a <= '9'))
	iSTACKpush(a - '0');
    }
  return iSTACKpop();
}
