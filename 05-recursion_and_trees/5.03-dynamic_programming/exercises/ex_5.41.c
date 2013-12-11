#include <stdio.h> 
#include <math.h>

#define N 10

int a[N+1];
int unknown = -1;

int P(int n)
{

  int f = (int)floor((float)n / 2.0);
  int c = (int)ceil((float)n / 2.0);
  int t;
  
  if (a[n] != unknown)
    return a[n];
  if (n == 0)
    t = 0;
  if (n == 1)
    t = 0;
  if (n > 1)
    t = f + P(f) + P(c);
  return (a[n] = t);
}

int main(void) 
{
  int i;

  for (i = 0; i <= N; i++)
    a[i] = unknown;
  printf("%d\n", P(N));
  return 0;
}
