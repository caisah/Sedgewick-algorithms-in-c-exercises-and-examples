#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "st.h"

#define null(A) (key(st[A]) == key(NULLitem))

static int N, M;
static Item *st;

int hashtwo(char *v, int M)
{
  int h = 0;
  int a = 97;

  for (; *v != '\0'; v++)
    h = (a*h + *v) % M;
  return h;
}
int hash(char *v, int M)
{
  int h, a = 31415, b = 27183;

  for (h = 0; *v != '\0'; v++, a = a*b % (M-1))
    h = (a*h + *v) % M;
  return h;
}

int eq(char *a, char *b)
{
  return (strcmp(a, b) == 0);
}

void STinit(int max)
{
  int i;

  N = 0;
  M = 2*max;
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
  int k = hashtwo(v, M);
  
  while (!null(i))
    i = (i+k) % M;
  st[i] = item;
  N++;
}

Item STsearch(Key v)
{
  int i = hash(v, M);
  int k = hashtwo(v, M);
  
  while (!null(i))
    if (eq(v, key(st[i])))
      return st[i];
    else
      i = (i+k) % M;
  return NULLitem;
}
