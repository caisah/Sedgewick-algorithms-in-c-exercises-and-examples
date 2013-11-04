#include <stdio.h>
#include <math.h>
#include <string.h>
#include "item.h"
#include "stack.h"

int main(void) 
{
  char *a = "-2 $9 +";
  int i, n = strlen(a), second;
  char operation = '0';

  STACKinit(n);
  for (i = 0; i < n; i++)
    {
      if (a[i] == '+')
	STACKpush(STACKpop() + STACKpop());
      if (a[i] == '*')
	STACKpush(STACKpop() * STACKpop());
      if ((a[i] == '-') && (a[i+1] == ' '))
	{
	  second = STACKpop();
	  STACKpush(STACKpop() - second);
	}
      if (a[i] == '/')
	{
	  second = STACKpop();
	  STACKpush(STACKpop() / second);
	}
      if ((a[i] == '-') && (a[i+1] >= '0') && (a[i+1] <= '9'))
	{
	  operation = 'n';
	  i++;
	}
      if ((a[i] == '$') && (a[i+1] >= '0') && (a[i+1] <= '9'))
	{
	  operation = 's';
	  i++;
	}
      if ((a[i] >= '0') && (a[i] <= '9'))
	STACKpush(0);
      while ((a[i] >= '0') && (a[i] <= '9'))
	  STACKpush(STACKpop() * 10 + (a[i++] - '0'));
      switch (operation)
	{
	case 'n':
	  STACKpush(STACKpop() * (-1));
	  operation = '0';
	  break;
	case 's':
	  STACKpush(sqrt(STACKpop()));
	  operation = '0';
	  break;
	}
    }
  printf("%f \n", STACKpop());
  return 0;
}
