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

void QUEUEput_begin(Item item)
{
  head = head % n;
  q[head] = item;
}

void QUEUEput_end(Item item)
{
  q[tail++] = item;
  tail = tail % n;
}

Item QUEUEget_begin()
{
  head = head % n;
  return q[head++];
}

Item QUEUEget_end()
{
  Item item;
  tail = (tail + n - 1) % n;
  item = q[tail++];
  tail = tail % n;
  return item;
}
