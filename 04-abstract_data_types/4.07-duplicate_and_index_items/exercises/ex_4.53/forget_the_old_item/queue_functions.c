#include <stdlib.h>
#include <stdio.h> 
#include "item.h"
#include "queue.h"

typedef struct QUEUEnode *link;
struct QUEUEnode
{
  Item item;
  link next;
};

static link head, tail;

void forget_old(Item item)
{
  link h = head, t;

  if (h->next == NULL)
    return;
  if (h->next == tail)
    {
      if (item == h->item)
	{
	  t = tail;
	  h->next = NULL;
	  free(t);
	  tail = h;
	  return;
	}
      else
	return;
    }
  while (h->next != tail)
    {
      if (h->next->item == item)
	{
	  t = h->next;
	  h->next = t->next;
	  free(t);
	  return;
	}
      h = h->next;
    }
}

link new(Item item, link next)
{
  link x = malloc(sizeof(*x));

  x->item = item;
  x->next = next;
  return x;
}

void QUEUEinit(int maxn)
{
  head = NULL;
}

int QUEUEempty(void)
{
  return head == NULL;
}

void QUEUEput(Item item)
{
  if (head == NULL)
    {
      head = (tail = new(item, head));
      return;
    }
  tail->next = new(item, tail->next);
  tail = tail->next;
  forget_old(item);
}

Item QUEUEget(void)
{
  Item item = head->item;
  link t = head->next;

  free(head);
  head = t;
  return item;
}
