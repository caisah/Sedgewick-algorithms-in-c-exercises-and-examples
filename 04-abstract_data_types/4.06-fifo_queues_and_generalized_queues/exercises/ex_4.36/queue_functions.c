#include <stdio.h> 
#include <stdlib.h> 
#include "item.h"
#include "queue.h"

typedef struct QUEUEnode *link;
struct QUEUEnode
{
  Item item;
  link next;
};

void QUEUEerror(const char *);

static link head, tail;
static int count = 0, n;

/* new: returns new link pointing to next elem */
link new(Item item, link next)
{
  link x = malloc(sizeof(*x));

  if (x == NULL)
    count = n;
  else
    count++;
  x->item = item;
  x->next = next;
  return x;
}

void QUEUEinit(int maxn)
{
  head = NULL;
  n = maxn;
}

int QUEUEempty(void)
{
  return head == NULL;
}

int QUEUEfull(void)
{
  return count >= n;
}

void QUEUEerror(const char *msg)
{
  printf("Queue Error: %s\n", msg);
}

/* QUEUEput_begin: adds element at the beginning of the queue */
void QUEUEput_begin(Item item)
{
  if (QUEUEfull())
    QUEUEerror("put");
  else
    {
      if (head == NULL)
	{
	  head = ( tail = new(item, head));
	  return;
	}
      head = new(item, head);
    }
}

/* QUEUEput_end: adds element at the end of the queue */
void QUEUEput_end(Item item)
{
  if (QUEUEfull())
    QUEUEerror("put");
  else
    {
      if (head == NULL)
	{
	  head = (tail = new(item, head));
	  return;
	}
      tail->next = new(item, tail->next);
      tail = tail->next;
    }
}

/* QUEUEget_begin: gets the element at the beginning of the queue */
Item QUEUEget_begin(void)
{
  if (QUEUEempty())
    {
      QUEUEerror("get");
      return '0';
    }
  else
    {
      Item item = head->item;
      link t = head->next;
      free(head);
      head = t;
      count--;
      return item;
    }
}

/* QUEUEget_end: gets the element at the end of the queue */
Item QUEUEget_end(void)
{
  link t = head;
  Item item;

  // if queue is empty
  if (QUEUEempty())
    {
      QUEUEerror("get");
      item = '0';
    }
  else
    {
      // if queue has only one element
      if (t->next == NULL)
	{
	  item = t->item;
	  free(t);
	  head = ( tail = NULL);
	}
      else
	{
	  // go to the penultimate element
	  while(t->next->next != NULL)
	    t = t->next;
	  item = t->next->item;
	  free(t->next);
	  t->next = NULL;
	  tail = t;
	}
      count--;
    }
  return item;
}
