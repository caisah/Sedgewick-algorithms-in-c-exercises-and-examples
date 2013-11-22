#include <stdlib.h> 
#include "uf.h"

struct UF
{
  int *id;
  int *sz;
};

uf UFinit(int N)
{
  int i;
  uf f;

  f = malloc(sizeof(uf));
  f->id = malloc(N * sizeof(int));
  f->sz = malloc(N * sizeof(int));
  for (i = 0; i < N; i++)
    {
      f->id[i] = i;
      f->sz[i] = 1;
    }
  return f;
}

int find(uf f, int x)
{
  int i = x;

  while (i != f->id[i])
    i = f->id[i];
  return i;
}

int UFfind(uf f, int p, int q)
{
  return ( find(f, p) == find(f, q));
}

void UFunion(uf f, int p, int q)
{
  int i = find(f, p), j = find(f, q);

  if(i == j)
    return;
  if (f->sz[i] < f->sz[j])
    {
      f->id[i] = j;
      f->sz[j] += f->sz[i];
    }
  else
    {
      f->id[j] = i;
      f->sz[i] += f->sz[j];
    }
}


