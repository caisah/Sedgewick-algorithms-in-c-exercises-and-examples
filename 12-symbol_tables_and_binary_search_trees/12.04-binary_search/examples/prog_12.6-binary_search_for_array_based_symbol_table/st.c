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

Item search(int l, int r, Key v)
{
  int m = (l+r)/2;

  if (l > r)
    return NULLitem;
  if (eq(v, key(st[m])))
    return st[m];
  if (l == r)
    return NULLitem;
  if (less(v, key(st[m])))
    return search(l, m-1, v);
  else
    return search(m+1, r, v);
  
}
Item STsearch(Key v)
{
  return search(0, N-1, v);
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
