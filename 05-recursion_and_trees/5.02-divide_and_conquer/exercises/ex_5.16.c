#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#define N 10

int max(int a[], int i, int n)
{
  int m;

  if (i == n)
    return a[n];
  return (m = max(a, i+1, n)) > a[i] ? m : a[i];
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
