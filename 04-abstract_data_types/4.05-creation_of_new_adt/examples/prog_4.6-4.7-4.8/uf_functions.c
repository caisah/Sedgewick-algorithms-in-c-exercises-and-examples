#include <stdlib.h> 
#include "uf.h"

static int *id, *sz;

void UFinit(int n)
{
  int i;

  id = malloc(n * sizeof(int));
  sz = malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    {
      id[i] = i;
      sz[i] = 1;
    }
}

static int find(int x)
{
  int i = x;

  while (i != id[i])
    i = id[i];
  return i;
}

int UFfind(int p, int q)
{
  return (find(p) == find(q));
}

void UFunion(int p, int q)
{
  int i = find(p), j = find(q);
  
  if (i == j)
    return;
  if (sz[i] < sz[j])
    {
      id[i] = j;
      sz[j] += sz[i];
    }
  else
    {
      id[j] = i;
      sz[i] += sz[j];
    }
}
