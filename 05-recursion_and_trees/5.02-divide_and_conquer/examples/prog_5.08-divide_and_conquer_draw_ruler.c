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
  int m = (l+r)/2;

  if (h > 0)
    {
      rule(l, m, h-1);
      mark(m, h);
      rule(m, r, h-1);
    }
}

int main(void) 
{
  int l = 0, r = N, h = (l+r) /2-1, i, j;

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
  return 0;
}
