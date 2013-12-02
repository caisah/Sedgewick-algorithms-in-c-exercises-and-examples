#include <stdlib.h>
#include <stdio.h> 
#include "item.h"
#include "list.h"

#define N 6

int count(link x)
{
  if (x == NULL)
    return 0;
  return 1 + count(x->next);
}

void traverse(link h, void (*visit)(link))
{
  if (h == NULL)
    return;
  (*visit)(h);
  traverse(h->next, visit);
}

void traverseR(link h, void (*visit)(link))
{
  if (h == NULL)
    return;
  traverseR(h->next, visit);
  (*visit)(h);
}

link delete(link x, Item v)
{
  if (x == NULL)
    return NULL;
  if (eq(x->item, v))
    {
      link t = x->next;
      free(x);
      return t;
    }
  x->next = delete(x->next, v);
  return x;
}

void node_print(link t)
{
  print_item(t->item);
}

int main(void) 
{
  link head, l;
  int i;

  head = list_init(0);
  for (i = 1, l = head; i < N; i++)
    {
      list_insert_next(l, i);
      l = l->next;
    }
  printf("\nCount: %d\n", count(head));
  traverse(head, node_print);
  printf("\n");
  traverseR(head, node_print);
  printf("\n");
  delete(head, 3);
  traverse(head, node_print);
  printf("\n");
  return 0;
}
