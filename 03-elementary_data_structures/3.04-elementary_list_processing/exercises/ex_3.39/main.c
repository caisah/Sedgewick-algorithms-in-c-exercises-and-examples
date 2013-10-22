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
  link *head = t;

  while (t != NULL)
    {
      if (!(f(head)))
	head = t->next;
      else
	if (!(f(t)))
	  delete_node(head, t);
      t = t->next;
    }
  return head;
}

int main(void) 
{
  link *t;

  t = new_list();
  print_list(t);
  t = remove_items(*func, t);
  print_list(t);
  return 0;
}

