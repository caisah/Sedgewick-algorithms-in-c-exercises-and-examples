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

void QUEUEput(Item item)
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

Item QUEUEget(void)
{
  if (QUEUEempty())
    QUEUEerror("get");
  else
    {
      Item item = head->item;
      link t = head->next;
      free(head);
      head = t;
      count--;
      return item;
    }
  return 0;
}

void QUEUEerror(const char *msg)
{
  printf("Queue Error: %s\n", msg);
}
