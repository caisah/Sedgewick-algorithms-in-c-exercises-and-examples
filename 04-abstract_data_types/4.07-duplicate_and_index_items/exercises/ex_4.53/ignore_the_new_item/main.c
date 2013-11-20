#include <stdio.h> 
#include "queue.h"

int main(void) 
{
  int n = 4;

  QUEUEinit(n);
  QUEUEput(1);
  QUEUEput(1);
  QUEUEput(3);
  printf("%d\n", QUEUEget());
  printf("%d\n", QUEUEget());
  return 0;
}
