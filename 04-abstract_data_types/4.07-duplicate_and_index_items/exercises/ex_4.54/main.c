#include <stdio.h> 
#include "queue.h"

int main(void) 
{
  int n = 4;

  QUEUEinit(n);
  QUEUEput(1);
  QUEUEput(2);
  QUEUEput(3);
  QUEUEput(3);
  QUEUEput(3);
  QUEUEput(2);
  printf("%d\n", QUEUEget());
  printf("%d\n", QUEUEget());
  printf("%d\n", QUEUEget());
  return 0;
}
