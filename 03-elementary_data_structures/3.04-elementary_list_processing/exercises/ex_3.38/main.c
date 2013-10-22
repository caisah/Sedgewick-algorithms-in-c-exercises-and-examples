#include <stdio.h>
#include <stdlib.h>
#include "list.h"

link *list_copy(link *t)
{
  link *new, *u = NULL, *head;

  while (t != NULL)
    {
      if (u == NULL)
	{
	  u = new_node(t->item);
	  head = u;
	}
      else
	{
	  new = new_node(t->item);
	  u->next = new;
	  u = new;
	}
      t = t->next;
    }
  return head;
}
int main(void) 
{
  link *t, *u;

  t = new_list();
  print_list(t);
  t = t->next;
  u = list_copy(t);
  print_list(u);
  return 0;
}

