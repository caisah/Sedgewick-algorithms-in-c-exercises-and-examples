#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"

// prev_char: returns the previous character other than space
char prev_char(char *a, int i)
{
  i--;
  while (i > 0 && a[i] == ' ')
    --i;
  return a[i];
}

/* transforms infix expression into postfix expression
      uses "n" for negative operator and "$" for square root */
int main(void) 
{
  char *a = "((-(-1)) + $((((-1) * (-1))-(4 * (-1)))))/2";
  /* char *a = "($(4 + 3 * (1 + 1)))"; */
  int i, n = strlen(a);
  char op;

  STACKinit(n);
  for (i = 0; i < n; i++)
    {
      if (a[i] == '$')
	STACKpush('$');
      if ((a[i] == '-') && (prev_char(a, i) !=')'))
	STACKpush('n');
      else if ((a[i] == '-'))
  	STACKpush(a[i]);
      if (a[i] == '+')
	STACKpush(a[i]);
      if (a[i] == ')' && !STACKempty())
	printf("%c ", STACKpop());
      if ((a[i] == '*') || (a[i] == '/'))
  	STACKpush(a[i]);
      if ((a[i] >= '0') && (a[i] <= '9'))
  	printf("%c ", a[i]);
    }
  // pop the remaining operations
  while (!STACKempty())
    printf("%c ", STACKpop());
  printf("\n");
  return 0;
}
