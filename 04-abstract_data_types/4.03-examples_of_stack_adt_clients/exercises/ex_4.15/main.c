#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"

// evaluates postfix expression
int main(void) 
{
  char *a = "3 2 1 4 + * +";
  int i, n = strlen(a), first = 1;

  STACKinit(n);
  for (i = 0; i < n; i++)
    switch (a[i])
      {
      case '+':
	if (first)
	  {
	    first = 0;
	    printf("(%c + %c) ", STACKpop(), STACKpop());
	  }
	else
	  {
	    printf("+ ");
	    printf("%c ", STACKpop());
	  }
	break;
      case '*':
	if (first)
	  {
	    printf("%c * %c ", STACKpop(), STACKpop());
	    first = 0;
	  }
	else
	  {
	    printf("* ");
	    printf("%c ", STACKpop());
	  }
	break;
      case ' ':
	break;
      default:
	STACKpush(a[i]);
      }
  printf("\n");
  return 0;
}
