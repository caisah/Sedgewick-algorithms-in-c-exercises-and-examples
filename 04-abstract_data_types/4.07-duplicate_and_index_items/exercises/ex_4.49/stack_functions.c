#include <stdlib.h>
#include "stack.h"
#include "item.h"

static Item *s;
static int N;

/* forget_old: checks for duplicate item;
   eliminates the old item if found */
void forget_old(Item item)
{
  int i, j;
  
  for (i = 0; i < N; i++)
    if (s[i] == item)
      {
	for(j = i; j < N; j++ )
	  s[j] = s[j+1];
	N--;
	return;
      }
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
    s[++N] = item;
    forget_old(item);
}
Item STACKpop(void)
{
  return s[N--];
}
