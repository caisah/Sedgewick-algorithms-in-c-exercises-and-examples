#include <stdlib.h>
#include <stdio.h> 
#include "item.h"
#include "list.h"

#define N 6

link h;

link reversed_list(link t)
{
  if (t->next == NULL)
    {
      h = t;
      return t;
    }
  reversed_list(t->next)->next = t;
  t->next = NULL;
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
  list_print(head);
  printf("\n");
  reversed_list(head);
  list_print(h);
  printf("\n");
  return 0;
}
