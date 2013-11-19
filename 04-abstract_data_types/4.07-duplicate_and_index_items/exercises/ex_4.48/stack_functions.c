#include <stdlib.h>
#include "stack.h"
#include "item.h"

static Item *s;
static int N;

/* is_duplicate: checks for duplicates in the stack
   array, using brute force */
int is_duplicate(Item item)
{
  int i;

  for (i = 0; i <= N; i++)
    if (s[i] == item)
      return 1;
  return 0;
}

void STACKinit(int maxn)
{
  s = malloc(maxn * sizeof(Item));
  N = 0;
}

int STACKempty(void)
{
  return N == 0;
}

void STACKpush(Item item)
{
  if (!is_duplicate(item))
    s[++N] = item;
}
Item STACKpop(void)
{
  return s[N--];
}
