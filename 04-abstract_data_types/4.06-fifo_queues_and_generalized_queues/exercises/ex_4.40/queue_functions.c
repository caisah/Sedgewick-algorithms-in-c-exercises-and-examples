#include <stdlib.h> 
#include "item.h"
#include "queue.h"

typedef struct QUEUEnode *link;
struct QUEUEnode
{
  Item item;
  link next;
};

static link head, tail;

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
}

Item QUEUEget(void)
{
  Item item = head->item;
  link t = head->next;

  free(head);
  head = t;
  return item;
}
