#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define N 12

int check_cycle(link *t, link *u)
{
  link *first = t;

  while (t->next != first)
    {
      if (t == u)
	return 1;
      t = t->next;
    }
  return 0;
}  

int main(void) 
{
  link *t, *u;
  
  t = create_list(N);
  print_list(t);
  u = create_list(N-4);
  print_list(u);
  printf("t and t->next->next end up on the same cycle: %d\n",
	 check_cycle(t, t->next->next));
  printf("t and u end up on the same cycle: %d\n",
	 check_cycle(t,u));
  return 0;
}
