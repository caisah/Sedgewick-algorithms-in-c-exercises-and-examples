#include <stdlib.h> 
#include "item.h"
#include "queue.h"

typedef struct QUEUEnode *link;
struct QUEUEnode
{
  Item item;
  link next;
};
struct queue
{
  link head;
  link tail;
};

link new(Item item, link next)
{
  link x = malloc(sizeof *x);

  x->item = item;
  x->next = next;
  return x;
}

Q QUEUEinit(int maxN)
{
  Q q = malloc(sizeof *q);

  q->head = NULL;
  return q;
}

int QUEUEempty(Q q)
{
  return q->head == NULL;
}

void QUEUEput(Q q, Item item)
{
  if (q->head == NULL)
    {
      q->tail = new(item, q->head);
      q->head = q->tail;
      return;
    }
  q->tail->next = new(item, q->tail->next);
  q->tail = q->tail->next;
}

Item QUEUEget(Q q)
{
  Item item = q->head->item;
  link t = q->head->next;

  free(q->head);
  q->head = t;
  return item;
}
