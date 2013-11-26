#include <stdio.h>
#include <string.h>
#include "item.h"
#include "stack.h"

#define N 4

int main(void) 
{
  S st;
  
  st = STACKinit(N);
  STACKpush(st, 1);
  STACKpush(st, 2);
  printf("%d, %d\n", STACKpop(st), STACKpop(st));
  printf("Stack empty? %d\n", STACKempty(st));
  return 0;
}
