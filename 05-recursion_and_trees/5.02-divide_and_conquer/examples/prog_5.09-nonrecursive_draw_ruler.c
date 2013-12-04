#include <stdio.h> 

#define N 8  // power of 2

int a[N];

void mark(int x, int y)
{
  int i;
  
  for(i = 0; i < y; i++)
    a[x]++;
}  

rule(int l, int r, int h)
{
  int i, j, t;

  for (t = 1, j = 1; t <= h; j += j, t++)
    for (i = 0; l+j+i <= r; i+= j+j)
      mark(l+j+i, t);
}

int main(void) 
{
  int l = 0, r = N, h = (l+r) /2, i, j;

  for (i = 0; i < N; i++)
    a[i] = 0;
  rule(l, r, h);
  for (i = 0; i < N; i++)
    {
      for (j = 0; j < a[i]; j++)
	printf("-");
      printf("\n");
      printf("\n");
    }
  printf("-\n");
  return 0;
}
