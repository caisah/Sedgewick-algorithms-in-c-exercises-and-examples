#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void free_list(link *t)
{
  link *d;
  
  while (t != NULL)
    {
      d = t;
      t = t->next;
      free(d);
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

