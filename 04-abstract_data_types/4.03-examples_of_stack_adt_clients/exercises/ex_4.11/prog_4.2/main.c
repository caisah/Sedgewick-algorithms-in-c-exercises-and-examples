#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"

int main(void) 
{
  char *a = "10 2 - 8 2 / +";
  int i, n = strlen(a), second;

  STACKinit(n);
  for (i = 0; i < n; i++)
    {
      if (a[i] == '+')
	STACKpush(STACKpop() + STACKpop());
      if (a[i] == '*')
	STACKpush(STACKpop() * STACKpop());
      if (a[i] == '-')
	{
	  second = STACKpop();
	  STACKpush(STACKpop() - second);
	}      
      if (a[i] == '/')
	{
	  second = STACKpop();
	  STACKpush(STACKpop() / second);
	}
      if ((a[i] >= '0') && (a[i] <= '9'))
	STACKpush(0);
      while ((a[i] >= '0') && (a[i] <= '9'))
	STACKpush(10 * STACKpop() + (a[i++] - '0'));
    }
  printf("%d \n", STACKpop());
  return 0;
}
