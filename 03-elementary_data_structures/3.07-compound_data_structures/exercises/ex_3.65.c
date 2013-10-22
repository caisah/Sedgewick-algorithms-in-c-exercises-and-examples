#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
  if (a == 0)
    return 0;
  if (b == 0)
    return 0;
  while (a != b)
    if (a > b)
      a = a - b;
    else
      b = b - a;
  return a;
}

int **malloc2d(int n, int m)
{
  int i;
  int **t = malloc(n * sizeof(int *));

  for (i = 0; i < n; i++)
    t[i] = malloc(m * sizeof(int));
  return t;
}

int main(void)
{
  int m, n, i, j;
  int **a;

  printf("Enter N: ");
  scanf("%d", &n);
  printf("Enter M: ");
  scanf("%d", &m);
  a = malloc2d(n, m);
  
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (gcd(i, j) == 1)
      	a[i][j] = 1;
      else
      	a[i][j] = 0;
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
  	printf("%d ", a[i][j]);
      printf("\n");
    }
  return 0;
}
