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

void show(link t)
{
  while (t != NULL)
    {
      printf("%d ", t->item);
      t = t->next;
    }
  printf("\n");
}

link findmax(link h)
{
  link max = h;

  h = max->next;
  while (h->next != NULL)
    {
      if (h->next->item > max->next->item)
	max = h;
      h = h->next;
    }
  return max;
}

link sort(link head)
{
  link max, t, out = NULL, h = malloc(sizeof(link));

  h->next = head;
  while(h->next != NULL)
    {
      max = findmax(h);
      t = max->next;
      max->next = t->next;
      t->next = out;
      out = t;
    }
  h->next = out;
  return h->next;
}
