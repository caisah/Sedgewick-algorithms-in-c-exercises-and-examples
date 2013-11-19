#include <stdio.h> 
#include "stack.h"

int main(void) 
{
  int n = 4;

  STACKinit(n);
  STACKpush(1);
  STACKpush(2);
  STACKpush(3);
  STACKpush(3);
  printf("%d\n", STACKpop());
  printf("%d\n", STACKpop());
  printf("%d\n", STACKpop());
  return 0;
}
