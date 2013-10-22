#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) 
{
  link *t, *odd = NULL, *even = NULL;

  t = new_list();
  print_list(t);
  while (t != NULL)
    {
      odd = add_last(t->item, odd);
      t = t->next;
      even = add_last(t->item, even);
      t = t->next;
    }
  t = concat_lists(odd, even);
  print_list(t);
  return 0;
}

