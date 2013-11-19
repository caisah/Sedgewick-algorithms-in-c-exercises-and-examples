#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"

int main(void) 
{
  int n=4;
  
  STACKinit(n);
  STACKpush(0);
  STACKpush(1);
  STACKpush(1);
  STACKpush(2);
  STACKpush(2);
  STACKpush(2);
  printf("%d\n", STACKpop());
  printf("%d\n", STACKpop());
  printf("%d\n", STACKpop());
  return 0;
}
