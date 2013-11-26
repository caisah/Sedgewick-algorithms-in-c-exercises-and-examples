#include <stdlib.h>
#include "stack.h"
#include "item.h"

struct stack
{
  int len;
  Item *s;
};

S STACKinit(int maxn)
{
  S st;
  
  st = malloc(sizeof(st));
  st->s = malloc(maxn * sizeof(Item));
  st->len = 0;
  return st;
}
int STACKempty(S st)
{
  return st->len == 0;
}
void STACKpush(S st, Item item)
{
  st->s[++st->len] = item;
}
Item STACKpop(S st)
{
  return st->s[st->len--];
}
