#include <stdio.h>
#include "queue.h"

int main(void) 
{
  int n = 4;
  
  QUEUEinit(n);
  QUEUEput_end('a');
  QUEUEput_end('b');
  QUEUEput_end('c');
  printf("%c\n", QUEUEget_end());
  printf("%c\n", QUEUEget_begin());
  printf("%c\n", QUEUEget_begin());
  return 0;
}
