#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>

#define N 10

int max(int a[], int l, int r)
{
  int u, v;
  int m = l + pow(2, ceil(log2(r - l + 1)) - 1) - 1;

  if (l == r)
    return a[l];
  u = max(a, l, m);
  v = max(a, m+1, r);
  if (u > v)
    return u;
  else
    return v;
}

int main(void) 
{
  int a[N], i;

  srand(time(NULL));
  for (i = 0; i < N; i++)
    a[i] = rand() % (2*N+1);
  for (i = 0; i < N; i++)
    printf("%d ", a[i]);
  printf("\nMax: %d\n", max(a, 0, N-1));
  return 0;
}
