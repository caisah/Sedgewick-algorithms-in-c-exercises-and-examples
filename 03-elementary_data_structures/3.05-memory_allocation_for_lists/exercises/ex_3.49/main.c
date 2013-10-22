#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void free_list(link *t)
{
  link *d, *head = t;
  int i = 1;
  
  while (t != NULL)
    {
      if ((i % 2) == 0)
	{
	  d = t;
	  t = t->next;
	  delete_node(head, d);
	  free(d);
	}
      else
	t = t->next;
      i++;
    }
}

int main(void) 
{
  link *t;

  t = new_list();
  print_list(t);
  free_list(t);
  print_list(t);
  return 0;
}

