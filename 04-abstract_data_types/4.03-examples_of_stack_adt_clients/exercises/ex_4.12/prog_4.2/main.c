#include <stdio.h>
#include <math.h>
#include <string.h>
#include "item.h"
#include "stack.h"

// evaluates postfix expression
int main(void) 
{
  char *a = "1 n n 1 n 1 n * 4 1 n * - $ + 2 / ";
  int i, n = strlen(a), second;

  STACKinit(n);
  for (i = 0; i < n; i++)
    {
      if (a[i] == '+')
	STACKpush(STACKpop() + STACKpop());
      if (a[i] == '*')
	STACKpush(STACKpop() * STACKpop());
      if (a[i] == '/')
	{
	  second = STACKpop();
	  STACKpush(STACKpop() / second);
	}
      if (a[i] == '-')
	{
	  second = STACKpop();
	  STACKpush(STACKpop() - second);
	}
      if ((a[i] >= '0') && (a[i] <= '9'))
	STACKpush(0);
      while ((a[i] >= '0') && (a[i] <= '9'))
	STACKpush(10 * STACKpop() + (a[i++] - '0'));
      if (a[i] == 'n')
	STACKpush(STACKpop() * (-1));
      if (a[i] == '$')
	STACKpush(sqrt(STACKpop()));
    }
  printf("%f \n", STACKpop());
  return 0;
}
