#include <stdlib.h>
#include "stack.h"
#include "item.h"

static Item *s;
static int N;
static int M;
static int MAX;

void STACKinit(int n)
{
  s = malloc(n * sizeof(Item));
  N = 0;
  M = n+1;
  MAX = n;
}

int beginSTACKempty(void)
{
  return N <= 0;
}

int endSTACKempty(void)
{
  return M >= MAX;
}

void beginSTACKpush(Item item)
{
  s[++N] = item;
}

void endSTACKpush(Item item)
{
  s[--M] = item;
}

Item beginSTACKpop(void)
{
  return s[N--];
}

Item endSTACKpop(void)
{
  return s[M++];
}
