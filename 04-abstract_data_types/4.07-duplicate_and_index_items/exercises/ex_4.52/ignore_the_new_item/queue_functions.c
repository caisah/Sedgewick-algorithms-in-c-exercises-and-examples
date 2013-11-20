#include <stdlib.h> 
#include "item.h"
#include "queue.h"

static Item *q;
static int n, head, tail;

/* dup: checks for item in q between start and end */
int dup(Item item, int start, int end)
{
  int i;

  for (i = start; i < end; i++)
    if (q[i] == item)
      return 1;
  return 0;
}  

/* is_duplicate: checks for duplicates in the queue */
int is_duplicate(Item item)
{
  int start = head % n;
  int end = tail % n;

  if (start == end)
    return 0;
  if (start < end)
    return dup(item, start, end);
  else
    return (dup(item, start, n-1) || dup(item, 0, end));
}

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
  if (!is_duplicate(item))
    {
      q[tail++] = item;
      tail = tail % n;
    }
}

Item QUEUEget()
{
  head = head % n;
  return q[head++];
}
