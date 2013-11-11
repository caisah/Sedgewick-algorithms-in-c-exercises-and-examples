#include <stdlib.h>
#include "stack.h"
#include "item.h"

static link head;

link new(Item item, link next)
{
  link x = malloc(sizeof *x);

  x->item = item;
  x->next = next;
  return x;
}

void STACKinit(int maxn)
{
  head = NULL;
}

int STACKempty(void)
{
  return head == NULL;
}

int STACKcount(void)
{
  link c = head;
  int count = 0;

  while (c != NULL)
    {
      count++;
      c = c->next;
    }
  return count;
}  

void STACKpush(Item item)
{
  head = new(item, head);
}

Item STACKpop()
{
  Item item = head->item;
  link t = head->next;

  free(head);
  head = t;
  return item;
}
