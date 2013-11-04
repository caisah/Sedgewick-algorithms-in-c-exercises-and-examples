#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"

char prev_char(char *a, int i)
{
  i--;
  while (i > 0 && a[i] == ' ')
    --i;
  return a[i];
}

int main(void) 
{
  char *a = "(-(-1) + $(2 + 3))";
  int i, n = strlen(a);

  STACKinit(n);
  for (i = 0; i < n; i++)
    {
      if (a[i] == '$')
	printf("$");
      if ((a[i] == '-') && (prev_char(a, i) == '('))
  	printf("0 - %c", a[i]);
      if ((a[i] == '-') && (prev_char(a, i) == ')'))
  	STACKpush(a[i]);
      if (a[i] == ')' && !STACKempty())
  	printf("%c ", STACKpop());
      if ((a[i] == '+') || (a[i] == '*') || (a[i] == '/'))
  	STACKpush(a[i]);
      if ((a[i] >= '0') && (a[i] <= '9'))
  	printf("%c ", a[i]);
    }
  printf("\n");
  return 0;
}
