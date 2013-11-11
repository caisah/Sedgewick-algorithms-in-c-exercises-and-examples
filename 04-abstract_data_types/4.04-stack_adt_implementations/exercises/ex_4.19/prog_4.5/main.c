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
  STACKpush(1);
  STACKpush(2);
  printf("Count: %d\n", STACKcount());
  printf("%d, %d\n", STACKpop(), STACKpop());
  printf("Stack empty? %d\n", STACKempty());
  return 0;
}
