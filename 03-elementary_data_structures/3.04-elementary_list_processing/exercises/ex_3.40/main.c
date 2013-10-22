#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int func(link *t)
{
  if (t->item % 2)
    return 0;
  else return 1;
}

link *remove_items(int (*f)(link*), link *t)
{
  link *new, *head, *l = NULL;

  while (t != NULL)
    {
      if (f(t))
	if (l != NULL)
	  {
	    new = new_node(t->item);
	    l->next = new;
	    l = new;
	  }
	else
	  {
	    new = new_node(t->item);
	    head = new;
	    l = new;
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
  u = remove_items(*func, t);
  print_list(u);
  return 0;
}

