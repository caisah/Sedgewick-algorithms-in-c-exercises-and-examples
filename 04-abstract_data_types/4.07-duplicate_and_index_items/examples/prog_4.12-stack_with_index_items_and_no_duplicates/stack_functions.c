#include <stdlib.h> 
#include "stack.h"

static int *s, *t;
static int n;

void STACKinit(int maxn)
{
  int i;

  s = malloc(maxn * sizeof(int));
  t = malloc(maxn * sizeof(int));
  for (i = 0; i < maxn; i++)
    t[i] = 0;
  n = 0;
}

int STACKempty(void)
{
  return !n;
}

void STACKpush(int item)
{
  if (t[item] == 1)
    return;
  s[n++] = item;
  t[item] = 1;
}

int STACKpop(void)
{
  n--;
  t[s[n]] = 0;
  return s[n];
}
