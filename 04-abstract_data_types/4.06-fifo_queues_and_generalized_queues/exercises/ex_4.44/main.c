#include <stdio.h>
#include "queue.h"

#define F 5

int main(void) 
{
  int n = 100, i;
  
  QUEUEinit(n-1);
  for(i = 1; i < n; i++)
    QUEUEput(i);
  for (i = 0; i < F; i++)
    printf("%d\n", QUEUEget());
  return 0;
}
