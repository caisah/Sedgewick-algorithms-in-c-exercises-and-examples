#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int **malloc2d(int r, int c)
{
  int i;
  int **t = malloc(r * sizeof(int *));
  for (i = 0; i < r; i++)
    t[i] = malloc(c * sizeof(int));
  return t;
}

link *new(int val, link *next)
{
  link *t;

  t = malloc(sizeof(link));
  t->val = val;
  t->next = next;
  return t;
}

void print_list(link *t)
{
  while (t != NULL)
    {
      printf("%d ",t->val);
      t = t->next;
    }
  printf("\n");
}
