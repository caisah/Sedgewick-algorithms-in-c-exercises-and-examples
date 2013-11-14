#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
#include "queue.h"

int main(void) 
{
  int n = 4;

  QUEUEinit(n);
  QUEUEput_begin('a');
  QUEUEput_begin('b');
  printf("%c\n", QUEUEget_begin());
  printf("%c\n", QUEUEget_begin());
  QUEUEput_end('x');
  printf("%c\n", QUEUEget_end());
  QUEUEput_begin('y');
  printf("%c\n", QUEUEget_begin());
  return 0;
}
