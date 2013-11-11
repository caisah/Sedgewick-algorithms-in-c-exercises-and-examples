#include <stdio.h> 
#include <stdlib.h>
#include "stack.h"
#include "item.h"

static link head;
static int M;

link new(Item item, link next)
{
  link x = malloc(sizeof *x);

  x->item = item;
  x->next = next;
  return x;
}

void STACKinit(int maxn)
{
  head = NULL;
  M = maxn;
}

int STACKempty(void)
{
  return head == NULL;
}

int STACKcount(void)
{
  link c = head;
  int count = 0;

  while (c != NULL)
    {
      count++;
      c = c->next;
    }
  return count;
}  

void STACKpush(Item item)
{
  if (STACKcount() < M)
    head = new(item, head);
  else
    STACKerror("PUSH");
}

Item STACKpop()
{
  Item item;
  link t;

  if (STACKcount() > 0)
    {
      item = head->item;
      t = head->next;
      free(head);
      head = t;
      return item;
    }
  else
    {
      STACKerror("POP");
      return 0;
    }
}

void STACKerror(const char *msg)
{
  printf("Stack Error: %s\n", msg);
}
