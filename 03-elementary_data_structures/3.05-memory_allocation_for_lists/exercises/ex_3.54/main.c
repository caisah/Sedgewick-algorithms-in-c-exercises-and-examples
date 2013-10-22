#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define N 12

int count_nodes(link *t)
{
  link *first = t;
  int i = 1;

  while (t->next != first)
    {
      i++;
      t = t->next;
    }
  return i;
}  

int main(void) 
{
  link *t;
  
  t = create_list(N);
  print_list(t);
  printf("No of nodes: %d\n", count_nodes(t->next->next));
  return 0;
}
