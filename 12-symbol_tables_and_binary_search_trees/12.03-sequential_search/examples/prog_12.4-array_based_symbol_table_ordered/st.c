#include <stdlib.h> 
#include "item.h"
#include "st.h"

#define less(A, B) ((A) < (B))
#define eq(A, B) ((A) == (B))

static Item *st;
static int N;


void STinit(int M)
{
  st = malloc((M)*sizeof(Item));
  N = 0;
}

int STcount()
{
  return N;
}

void STinsert(Item item)
{
  int j = N++;
  Key v = key(item);

  while(j>0 && less(v, key(st[j-1])))
    {
      st[j] = st[j-1];
      j--;
    }
  st[j] = item;
}

Item STsearch(Key v)
{
  int j;

  for (j = 0; j < N; j++)
    {
      if (eq(v, key(st[j])))
	return st[j];
      if (less(v, key(st[j])))
	break;
    }
  return NULLitem;
}

Item STselect(int k)
{
  return st[k];
}

void STsort(void (*visit) (Item))
{
  int i;

  for (i = 0; i < N; i++)
    visit(st[i]);
}
