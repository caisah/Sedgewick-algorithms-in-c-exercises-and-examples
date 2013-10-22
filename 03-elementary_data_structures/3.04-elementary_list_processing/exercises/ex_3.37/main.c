#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void exchange_nodes(link *t, link *u)
{
  int temp = t->item;

  t->item = u->item;
  u->item = temp;
}

int main(void) 
{
  link *l, *t, *u;

  l = new_list();
  t = l->next;
  u = l->next->next->next;
  print_list(l);
  exchange_nodes(t, u);
  print_list(l);
  return 0;
}

