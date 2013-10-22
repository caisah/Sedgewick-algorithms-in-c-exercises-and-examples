#include <stdio.h>
#include <stdlib.h>

int **malloc2d(int r, int c)
{
  int i;
  int **t = malloc(r * sizeof(int *));
  for (i = 0; i < r; i++)
    t[i] = malloc(c * sizeof(int));
  return t;
}

int main(void)
{
  int n, m, **a;

  printf("Enter n: ");
  scanf("%d", &n);
  printf("Enter m: ");
  scanf("%d", &m);
  a = malloc2d(m, n);
  return 0;
}
