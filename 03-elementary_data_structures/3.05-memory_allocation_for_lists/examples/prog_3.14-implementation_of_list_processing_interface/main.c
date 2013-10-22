#include <stdio.h>
#include "list.h"

#define N 1000

int main(void) 
{
  link t, u;

  initNodes(N);
  t = newNode(1);
  u = newNode(2);
  insertNext(t, u);
  return 0;
}
