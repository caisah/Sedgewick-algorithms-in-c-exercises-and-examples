#include <stdlib.h>
#include "stack.h"
#include "item.h"

static Item *s;
static int N;

void STACKinit(int maxn)
{
  s = malloc(maxn * sizeof(Item));
  N = 0;
}
int STACKcount(void)
{
  return N;
}
int STACKempty(void)
{
  return N == 0;
}
void STACKpush(Item item)
{
  s[++N] = item;
}
Item STACKpop(void)
{
  return s[N--];
}
