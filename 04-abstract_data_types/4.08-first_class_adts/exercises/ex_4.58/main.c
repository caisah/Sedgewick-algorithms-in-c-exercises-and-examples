#include <stdio.h>
#include <stdlib.h> 
#include "uf.h"

int main(int argc, char *argv[]) 
{
  int p, q, N = atoi(argv[1]);
  uf f;
  
  f = UFinit(N);
  while (scanf("%d %d", &p, &q) == 2)
    if (!UFfind(f, p, q))
      {
	UFunion(f, p, q);
	printf("%d %d\n", p, q);
      }
  return 0;
}
