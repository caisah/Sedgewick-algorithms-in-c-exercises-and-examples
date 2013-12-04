#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

#define N 10

int max (int a[], int l, int r)
{
  int u, v;
  int m = (l+r)/2;

  if (l == r)
    return a[l];
  u = max(a, l, m);
  v = max(a, m+1, r);
  return (u > v) ? u : v;
}

int main(void) 
{
  int i, a[N];

  srand(time(NULL));
  for (i = 0; i < N; i++)
    a[i] = rand() % (2 * N);
  for (i = 0; i < N; i++)
    printf("%d ", a[i]);
  printf("\n");
  printf("Max: %d\n", max(a, 0, N-1));
  return 0;
}
