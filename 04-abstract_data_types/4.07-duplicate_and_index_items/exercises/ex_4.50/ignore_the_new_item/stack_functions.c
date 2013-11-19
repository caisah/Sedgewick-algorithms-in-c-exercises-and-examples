#include <stdlib.h>
#include "stack.h"
#include "item.h"

static link head;

/* is_duplicate: checks to see if item is duplicate */
int is_duplicate(Item item)
{
  link h = head;

  while (h != NULL)
    {
      if (h->item == item)
	return 1;
      h = h->next;
    }
  return 0;
}

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

void STACKpush(Item item)
{
  if (!is_duplicate(item))
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
