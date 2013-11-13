#include <stdio.h> 
#include <stdlib.h> 
#include "item.h"
#include "queue.h"

static Item *q;
static int n, head, tail;

void QUEUEerror(const char*);
int QUEUEfull(void);

void QUEUEinit(int maxn)
{
  q = malloc( (maxn + 1) * sizeof(Item));
  n = maxn + 1;
  head = n;
  tail = 0;
}

int QUEUEempty(void)
{
  return head % n == tail;
}

int QUEUEfull(void)
{
  return (tail + 1) == head;
}

void QUEUEerror(const char *msg)
{
  printf("Queue Error: %s\n", msg);
}

void QUEUEput(Item item)
{
  if (QUEUEfull())
    QUEUEerror("put");
  else
    {
      q[tail++] = item;
      tail = tail % n;
    }
}

Item QUEUEget()
{
  if (QUEUEempty())
    QUEUEerror("get");
  else
    {
      head = head % n;
      return q[head++];
    }
  return 0;
}
