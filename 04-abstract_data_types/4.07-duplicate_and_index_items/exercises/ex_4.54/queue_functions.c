#include <stdlib.h>
#include "item.h"
#include "queue.h"

typedef struct QUEUEnode *link;
struct QUEUEnode
{
  Item item;
  link next;
  link prev;
};

static link head, tail, *t;
static int n;

void forget_duplicate(Item item)
{
  link l = t[item];
  link n, p;

  if (l == head)
    {
      head = head->next;
      head->prev = NULL;
      free(l);
    }
  else if (l == tail)
    {
      tail = l->prev;
      tail->next = NULL;
      free(l);
    }
  else
    {
      p = l->prev;
      n = l->next;
      p->next = n;
      n->prev = p;
      free(l);
    }
}  

link new(Item item, link next, link prev)
{
  link x = malloc(sizeof(*x));

  x->item = item;
  x->next = next;
  x->prev = prev;
  return x;
}

void QUEUEinit(int maxn)
{
  int i;

  n = maxn;
  t = malloc(n * sizeof(link));
  for (i = 0; i < n; i++)
    t[i] = NULL;
  head = NULL;
}

int QUEUEempty(void)
{
  return head == NULL;
}

void QUEUEput(Item item)
{
  if (head == NULL)             // put first element into the queue
    {
      head = ( tail = new(item, NULL, NULL));
      t[item] = head;
      return;
    }
  if (t[item] != NULL)          // if duplicate item
    {
      if (head->next == NULL)     // if only one item in queue
	{
	  free(head);             // delete item
	  head = NULL;
	  QUEUEput(item);         // put item in queue again
	  return;                 // exit
	}
      else
	forget_duplicate(item);   // eliminate duplicate
    }
  tail->next = new(item, NULL, tail);  // add the item
  tail = tail->next;
  t[item] = tail;
}

Item QUEUEget(void)
{
  Item item = head->item;
  link l;
  
  if (head->next == NULL)
    {
      free(head);
      head = NULL;
    }
  else
    {
      l = head->next;
      l->prev = NULL;
      free(head);
      head = l;
    }
  return item;
}
