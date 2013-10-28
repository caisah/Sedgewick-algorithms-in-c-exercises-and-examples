#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#define MAX(a,b) (((a)>(b))?(a):(b))

int main(void)
{
  link **multi;
  int r, c, i, j, max;
  int **mat;

  printf("Enter the no of rows: ");
  scanf("%d", &r);
  printf("Enter the no of columns: ");
  scanf("%d", &c);
  mat = malloc2d(r, c);
  max = MAX(r, c);
  multi = malloc(max * sizeof(link*));
  for (i = 0; i < max; i++)
    multi[i] = NULL;
  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
      mat[i][j] = 0;
  printf("Enter the col and row of nonzero elements: ");
  while (scanf("%d %d",&i, &j) != EOF)
    {
      printf("Enter a new coordinate or EOF to exit: ");
      if (i < r && j < c)
	mat[i][j] = 1;
      else
	printf("Not a valid matrix coordinate\n");
    }

  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
      if (mat[i][j])
	{
	  multi[j] = new(i, multi[j]);
	  multi[i] = new(j, multi[i]);
	}
  printf("\nList:\n");
  for (i = 0; i < r; i++)
    print_list(multi[i]);
  
  printf("\nMatrix:\n");
  for (i = 0; i < r; i++)
    {
      for (j = 0; j < c; j++)
	printf("%d ", mat[i][j]);
      printf("\n");
   }
  return 0;
}
