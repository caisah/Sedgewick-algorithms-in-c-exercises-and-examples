#include <stdio.h> 
#include <stdlib.h>
#include "stack.h"
#include "item.h"

static Item *s;
static int N, M;

void STACKinit(int maxn)
{
  s = malloc(maxn * sizeof(Item));
  N = 0;
  M = maxn;
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
  if (STACKcount() == M)
    STACKerror("PUSH");
  else
    s[++N] = item;
}
Item STACKpop(void)
{
  if (STACKcount() == 0)
    {
      STACKerror("POP");
      return 0;
    }
  else
    return s[N--];
}
void STACKerror(const char *msg)
{
  printf("Stack Error: Cannot %s\n", msg);
}
