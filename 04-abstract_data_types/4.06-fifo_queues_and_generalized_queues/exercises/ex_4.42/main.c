#include <stdio.h>
#include "queue.h"

int main(void) 
{
  int n = 4;
  
  QUEUEinit(n);
  QUEUEput('a');
  QUEUEput('b');
  QUEUEput('c');
  printf("%c\n", QUEUEget());
  printf("%c\n", QUEUEget());
  printf("%c\n", QUEUEget());
  return 0;
}
