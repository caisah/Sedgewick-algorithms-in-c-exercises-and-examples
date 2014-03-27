#include <stdlib.h>
#include <string.h>
#include <stdio.h> 
#include "item.h"
#include "st.h"

#define null(A) (key(st[A]) == key(NULLitem))

static int N, M;
static Item *st;
void expand();

int hash(char *v, int M)
{
  int h, a = 31415, b = 27183;

  for (h = 0; *v != '\0'; v++, a = a*b % (M-1))
    h = (a*h + *v) % M;
  return h;
}

void expand()
{
  int i;
  Item *t=st;

  STinit(M+M);
  for (i = 0; i < M/2; i++)
    if (key(t[i]) != key(NULLitem))
      STinsert(t[i]);
  free(t);
}  

int eq(char *a, char *b)
{
  return (strcmp(a, b) == 0);
}

void STinit(int max)
{
  int i;

  N = 0;
  M = max;
  st = malloc(M*sizeof(Item));
  for (i = 0; i < M; i++)
    st[i] = NULLitem;
}


int STcount(void)
{
  return N;
}

void STinsert(Item item)
{
  Key v = key(item);
  int i = hash(v, M);

  while(!null(i))
    i = (i+1) % M;
  st[i] = item;
  if (N++ >= M/2)
    expand();
}

Item STsearch(Key v)
{
  int i = hash(v, M);
  while (!null(i))
    if (eq(v, key(st[i])))
      return st[i];
    else
      i = (i+1) % M;
  return NULLitem;
}
