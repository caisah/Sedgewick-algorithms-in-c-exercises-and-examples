#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"

int main(int argc, char *argv[]) 
{
  char *a = argv[1];
  int i, n = strlen(a);

  STACKinit(n);
  for (i = 0; i < n; i++)
    {
      if (a[i] == ')')
	printf("%c ", STACKpop());
      if ((a[i] == '+') || (a[i] == '*'))
	STACKpush(a[i]);
      if ((a[i] >= '0') && (a[i] <= '9'))
	printf("%c ", a[i]);
    }
  printf("\n");
  return 0;
}
