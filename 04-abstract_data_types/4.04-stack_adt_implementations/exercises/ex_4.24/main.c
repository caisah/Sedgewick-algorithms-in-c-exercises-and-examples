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
  beginSTACKpush(1);
  beginSTACKpush(11);
  beginSTACKpush(111);
  endSTACKpush(2);
  printf("%d\n", beginSTACKpop());
  printf("%d\n", beginSTACKpop());
  printf("%d\n", endSTACKpop());
  printf("End stack empty? %d\n", endSTACKempty());
  return 0;
}
