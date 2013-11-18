#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "queue.h"

typedef struct QUEUEnode *link;
struct QUEUEnode
{
  Item item;
  link next;
};

static link head, tail;
static int m;

link new(Item item, link next)
{
  link x = malloc(sizeof(*x));

  x->item = item;
  x->next = next;
  m++;
  return x;
}

void QUEUEinit(int maxn)
{
  head = NULL;
  srand(time(NULL));
  m = 0;
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
  Item item;
  link t = head, temp;
  int r = rand() % m;
  int i;

  if (r == 0)
    {
      item = head->item;
      t = head;
      head = head->next;
      free(t);
      m--;
      return item;
    }
  for (i = 0; i < (r-1); i++)
    t = t->next;
  item = t->next->item;
  temp = t->next;
  t->next = t->next->next;
  free(temp);
  m--;
  return item;			
}
