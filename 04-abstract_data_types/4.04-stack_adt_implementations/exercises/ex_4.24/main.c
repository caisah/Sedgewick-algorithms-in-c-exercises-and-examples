#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"

int main(void) 
{
  int n;
  
  printf("Enter the size of stack: ");
  scanf("%d", &n);
  STACKinit(n);
  endSTACKpush(2);
  endSTACKpush(3);
  printf("%d ", endSTACKpop());
  printf("%d\n", endSTACKpop());
  return 0;
}
