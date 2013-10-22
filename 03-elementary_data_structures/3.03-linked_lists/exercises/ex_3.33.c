#include <stdio.h>
#include <stdlib.h>

#define N 9
#define M 4

int main(void) 
{
  int i, x=0;
  int *item, *next;

  item = malloc(N*sizeof(int));
  next = malloc(N*sizeof(int));

  if (item != NULL)
    for (i = 0; i < N; i++)
      item[i] = i+1;
  if (next != NULL)
    for (i = 0; i < N-1; i++)
      next[i] = i+1;
  next[i] = 0;
  while (x != next[x])
    {
      for (i = 1; i < M; i++)
        x = next[x];
      next[x] = next[next[x]];
    }
  printf ("%d\n",item[x]);
  return 0;
}
