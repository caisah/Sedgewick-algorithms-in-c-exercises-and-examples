#include <stdio.h> 
#include <math.h>

#define N 5

int a[N+1];

int P(int i, int n)
{
  int f = (int)floor((float)i / 2.0);
  int c = (int)ceil((float)i / 2.0);

  if (i == 0)
    {
      a[0] = 0;
      a[1] = 0;
      return P(i+2, n);
    }
  a[i] = f + a[f] + a[c];
  if (i == n)
    return a[i];
  else
    P(i+1, n);
}

int main(void) 
{
  printf("%d\n", P(0, N));
  return 0;
}
