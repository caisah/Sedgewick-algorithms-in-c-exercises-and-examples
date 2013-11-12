#include <stdio.h>
#include <stdlib.h>
#include "uf.h"

int main(int argc, char *argv[])
{
  int p, q, n = atoi(argv[1]);
  
  UFinit(n);
  while (scanf("%d %d", &p, &q) == 2)
    if (!UFfind(p,q))
      {
	UFunion(p, q);
	printf(" %d %d\n", p, q);
      }
  return 0;
}
