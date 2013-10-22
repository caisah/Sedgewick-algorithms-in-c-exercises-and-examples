#include <stdio.h>
#include <stdlib.h>

int ***malloc3d(int m, int n, int p)
{
  int i, j;
  int ***t = malloc(m * sizeof(int **));
  
  for (i = 0; i < n; i++)
    {
      t[i] = malloc(n * sizeof(int *));
      for (j = 0; j < n; j++)
	t[i][j] = malloc(p * sizeof(int));
    }
  return t;
}

int main(void) 
{
  int m, n, o;
  int ***a;
  
  a = malloc3d(m, n, o);
  return 0;
}
