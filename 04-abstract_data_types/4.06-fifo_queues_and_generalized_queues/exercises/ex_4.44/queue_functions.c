#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "queue.h"

static Item *q;
static int n, m, head, tail;

/* QUEUEswap: swaps head with a random position element */
void QUEUEswap(void)
{
  Item temp;
  // generate random position
  int pos = rand() % m;
  // copy head into h
  int h = head % n;
  // swap head position with pos position
  if (pos != h)
    {
      pos = (h + pos) % n;
      temp = q[pos];
      q[pos] = q[h];
      q[h] = temp;
    }
}

void QUEUEinit(int maxn)
{
  q = malloc( (maxn + 1) * sizeof(Item));
  n = maxn + 1;
  m = 0;
  head = n;
  tail = 0;
  srand(time(NULL));
}

int QUEUEempty(void)
{
  return head % n == tail;
}

void QUEUEput(Item item)
{
  q[tail++] = item;
  tail = tail % n;
  m++;
}

Item QUEUEget()
{
  // swap a random queue element with head element
  QUEUEswap();
  head = head % n;
  m--;
  return q[head++];
}
