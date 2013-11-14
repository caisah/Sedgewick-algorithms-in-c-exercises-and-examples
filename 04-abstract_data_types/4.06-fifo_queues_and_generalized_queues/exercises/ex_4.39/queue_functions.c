#include <stdio.h> 
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

static link head, tail;
static int n;

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
  head = NULL;
  tail = NULL;
  n = maxn;
}

int QUEUEempty(void)
{
  return head == NULL;
}


void QUEUEput_begin(Item item)
{
  if (head == NULL)
    {
      head = ( tail = new(item, head, tail));
      return;
    }
  head = new(item, head, NULL);
}

/* QUEUEput_end: adds element at the end of the queue */
void QUEUEput_end(Item item)
{
  if (head == NULL)
    {
      head = ( tail = new(item, head, tail));
      return;
    }
  tail->next = new(item, NULL, tail->next);
  tail = tail->next;
}

/* QUEUEget_begin: gets the element at the beginning of the queue */
Item QUEUEget_begin(void)
{
  Item item = 0;
  link t;
  
  if (!QUEUEempty())
    {
      if (head->next == NULL)
	{
	  item = head->item;
	  free(head);
	  head = NULL;
	  tail = NULL;
	}
      else
	{
	  item = head->item;
	  t = head->next;
	  t->prev = NULL;
	  free(head);
	  head = t;
	}
    }
  return item;
}

/* QUEUEget_end: gets the element at the end of the queue */
Item QUEUEget_end(void)
{
  Item item = 0;
  link t;

  if (!QUEUEempty())
    {
      if (tail->prev == NULL)
	{
	  item = tail->item;
	  free(tail);
	  head = NULL;
	  tail = NULL;
	}
      else
	{
	  item = tail->item;;
	  t = tail->prev;
	  t->next = NULL;
	  free(tail);
	  tail = t;
	}
    }
  return item;
}
