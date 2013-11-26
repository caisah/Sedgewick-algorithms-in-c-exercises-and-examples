#include <stdlib.h>
#include "stack.h"
#include "item.h"

typedef struct STACKnode *link;
struct STACKnode 
{
  Item item;
  link next;
};
struct stack
{
  link head;
};

link new(Item item, link next)
{
  link x = malloc(sizeof *x);

  x->item = item;
  x->next = next;
  return x;
}

S STACKinit(int maxn)
{
  S st;

  st = malloc(sizeof(st));
  st->head = NULL;
  return st;
}

int STACKempty(S st)
{
  return st->head == NULL;
}

void STACKpush(S st, Item item)
{
  st->head = new(item, st->head);
}

Item STACKpop(S st)
{
  Item item = st->head->item;
  link t = st->head->next;

  free(st->head);
  st->head = t;
  return item;
}
