#include <stdlib.h> 
#include "item.h"
#include "queue.h"

static Item *q;
static int n, head, tail;

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

void QUEUEput(Item item)
{
  q[tail++] = item;
  tail = tail % n;
}

Item QUEUEget()
{
  head = head % n;
  return q[head++];
}
