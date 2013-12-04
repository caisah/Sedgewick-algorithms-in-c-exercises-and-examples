#include <stdlib.h>
#include <stdio.h> 
#include "item.h"
#include "list.h"

#define N 6

void delete_last(link t)
{
  link temp;
  
  if (t->next->next == NULL)
    {
      temp = t->next;
      t->next = NULL;
      free(temp);
    }
  else
    delete_last(t->next);
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
  delete_last(head);
  list_print(head);
  printf("\n");
  return 0;
}
