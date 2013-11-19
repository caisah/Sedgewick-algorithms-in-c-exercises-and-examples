#include <stdlib.h>
#include "stack.h"
#include "item.h"

static link head;
static link *t;

void delete_item(link l)
{
  link p = l->prev;
  link n = l->next;

  p->next = n;
  if (n != NULL)
    n->prev = p;
  free(l);
}

void forget_old(Item item)
{
  if (t[item] != NULL)
    {
      delete_item(t[item]);
      t[item] = NULL;
    }
}

link new(Item item, link next, link prev)
{
  link x = malloc(sizeof *x);
  
  x->item = item;
  x->next = next;
  x->prev = prev;
  return x;
}

void STACKinit(int maxn)
{
  int i;
  t = malloc(maxn * sizeof(link));

  head = NULL;
  // initialize pointer array
  for (i = 0; i < maxn; i++)
    t[i] = NULL;
}

int STACKempty(void)
{
  return head == NULL;
}

void STACKpush(Item item)
{
  link l;

  if (head == NULL)
    head = new(item, NULL, NULL);
  else
    {
      l = head;
      head = new(item, head, NULL);
      l->prev = head;
    }
  forget_old(item);
  t[item] = head;
}

Item STACKpop()
{
  Item item = head->item;
  link l = head->next;

  free(head);
  head = l;
  if (head != NULL)
    head->prev = NULL;
  return item;
}
