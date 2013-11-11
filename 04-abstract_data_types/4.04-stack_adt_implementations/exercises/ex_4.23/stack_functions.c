#include <stdio.h> 
#include <stdlib.h>
#include "stack.h"
#include "item.h"

static link head;
static link last;

/* void print_list() */
/* { */
/*   link h = head; */
/*   link l = last; */

/*   printf("From head: "); */
/*   while (h != NULL) */
/*     { */
/*       printf("%d ", h->item); */
/*       h = h->next; */
/*     } */
/*   printf("\n"); */
/*   printf("From tail: "); */
/*   while (l != NULL) */
/*     { */
/*       printf("%d ", l->item); */
/*       l = l->prev; */
/*     } */
/*   printf("\n\n"); */
/* } */

link new(Item item)
{
  link x = malloc(sizeof(link));

  x->item = item;
  if (head == NULL)
    {
      x->prev = head;
      x->next = last;
      head = x;
    }
  else
    {
      x->next = NULL;
      last->next = x;
      x->prev = last;
    }
  return x;
}

void STACKinit(int maxn)
{
  head = NULL;
  last = NULL;
}

int STACKempty(void)
{
  return head == NULL;
}

void STACKpush(Item item)
{
  last = new(item);
}

Item STACKpop()
{
  Item item = head->item;
  link t = head->next;

  free(head);
  head = t;
  return item;
}
