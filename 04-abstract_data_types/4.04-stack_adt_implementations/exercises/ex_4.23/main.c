#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"

int main(void) 
{
  int n;

  printf("Enter the seize of stack: ");
  scanf("%d", &n);
  STACKinit(n);
  STACKpush(1);
  STACKpush(11);
  STACKpush(111);
  printf("%d\n", STACKpop());
  printf("%d\n", STACKpop());
  printf("%d\n", STACKpop());
  return 0;
}
