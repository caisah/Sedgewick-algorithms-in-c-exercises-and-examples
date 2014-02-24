#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "list.h"

link init(int N)
{
  int i;
  link t, head = malloc(sizeof(link));
  
  srand(time(NULL));
  head->item = rand() % 1000;
  head->next = NULL;
  for (i = 0, t = head; i < N-1; i++)
    {
      t->next = malloc(sizeof *t);
      t = t->next;
      t->item = rand() % 1000;
    }
  t->next = NULL;
  return head;
}

void print_list(link t)
{
  while (t != NULL)
    {
      printf("%d ", t->item);
      t = t->next;
    }
  printf("\n");
}
