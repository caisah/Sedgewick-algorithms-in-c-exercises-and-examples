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
  STACKpop();
  STACKpop();
  return 0;
}
