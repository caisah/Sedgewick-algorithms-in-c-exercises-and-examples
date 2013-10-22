#include <stdio.h>
#include <stdlib.h>
#include "list.h"

link *new_node(int n)
{
  link *new;

  new = malloc(sizeof(link));
  if (new != NULL)
    {
      new->item = n;
      new->next = new;
    }
  return new;
}

link *create_list(int n)
{
  link *new,* first, *t = NULL;
  int i;

  for (i = 0; i < n; i++)
    if (t == NULL)
      {
	t = new_node(i + 1);
	first = t;
      }
    else
      {
	new = new_node(i + 1);
	new->next = first;
	t->next = new;
	t = new;
      }
  return first;
}

void print_list(link *t)
{
  link *first = t;

  while (t->next != first)
    {
      printf("%d ", t->item);
      t = t->next;
    }
  printf("%d", t->item);
  printf("\n");
}
