#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void exchange_nodes(link *t, link *u)
{
  link *temp = t->item;

  t->item = u->item;
  u->item = temp;
}

int main(void) 
{
  link *t, *u;

  t = new_list();
  print_list(t);
  u = t->next->next;
  exchange_nodes(t, u);
  print_list(t);
  return 0;
}

