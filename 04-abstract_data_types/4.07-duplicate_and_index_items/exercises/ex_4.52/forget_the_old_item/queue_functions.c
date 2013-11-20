#include <stdlib.h>
#include <stdio.h> 
#include "item.h"
#include "queue.h"

static Item *q;
static int n, head, tail;

/* is_duplicate: checks for duplicates in the queue */
void forget_old(Item item)
{
  int start = head % n;
  int end = tail % n;

  // if head and tail equal
  if (start == end)
    return;
  else
    while (start != end-1)             // iterate from head to tail
      {
	if (q[start] == item)          // if item is found move all next elements
	  {                            // of the array one position backward
	    while (start != (end-1))
	      {
		q[start] = q[(start+1) % n];
		start++;
		start = start % n;
	      }
	    tail--;
	    tail = tail % n;
	    return;
	  }
	start++;
	start = start % n;
      }
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
  q[tail++] = item;
  tail = tail % n;
  forget_old(item);
}

Item QUEUEget()
{
  head = head % n;
  return q[head++];
}
