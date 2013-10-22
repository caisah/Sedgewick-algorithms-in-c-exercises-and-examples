#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) 
{
  link *t, *head;
  struct node *d = NULL;
  int min;

  t = new_list();
  print_list(t);
  head = t;
  min = t->item;
  t = t->next;
  while (t != NULL)
    {
      if (t->item < min)
	min = t->item;
      t = t->next;
    }
  t = head;
  if (min != t->item)
    while (t->next != NULL)
      {
	if (t->next->item == min)
	  {
	    d = t->next;
	    if (d != NULL)
	      t->next = d->next;
	    else
	      t->next = NULL;
	    break;
	  }
	t = t->next;
      }
  d->next = head;
  head = d;
  print_list(head);
  return 0;
}

