#include <stdlib.h> 
#include "list.h"
#include "queue.h"

static link *q;
static int n, head, tail;

void QUEUEinit(int maxn)
{
  q = malloc( (maxn + 1) * sizeof(link));
  n = maxn + 1;
  head = n;
  tail = 0;
}

int QUEUEempty(void)
{
  return head % n == tail;
}

void QUEUEput(link item)
{
  q[tail++] = item;
  tail = tail % n;
}

link QUEUEget()
{
  head = head % n;
  return q[head++];
}
