#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int last_item(link *t)
{
  while (t->next != NULL)
    t = t->next;
  return t->item;
}

int main(void) 
{
  link *t, *head;
  struct node *d = NULL;
  int max, not_last = 1;

  t = new_list();
  print_list(t);
  head = t;
  max = t->item;
  t = t->next;
  while (t != NULL)
    {
      if (t->item > max)
	max = t->item;
      t = t->next;
    }
  t = head;
  if (max != last_item(t))
    {
      while (t->next != NULL)
	{
	  if (t->next->item == max)
	    {
	      d = t->next;
	      not_last = 0;
	      t->next = d->next;
	      d->next = NULL;
	    }
	  t = t->next;
	}
      t->next = d;
    }
  print_list(head);
  return 0;
}

