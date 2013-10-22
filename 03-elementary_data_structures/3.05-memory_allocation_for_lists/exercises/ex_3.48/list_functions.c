#include <stdio.h>
#include <stdlib.h>
#include "list.h"

link *new_node(int n)
{
  link *t;

  t = malloc(sizeof(link));
  if (t != NULL)
    {
      t->item = n;
      t->next = NULL;
    }
  return t;
}

link *new_list()
{
  int n;
  link *head, *new, *t = NULL;

  printf("Enter list members: ");
  while (!feof(stdin))
    {
      scanf("%d ",&n);
      new = new_node(n);
      if (t == NULL)
	{
	  t = new;
	  head = t;
	}
      else
	{
	  t->next = new;
	  t = t->next;
	}
    }
  printf("\n");
  return head;
}

void delete_node(link *t, link *d)
{
  if (d->next != NULL)
    {
      while (t->next->item != d->item)
	t = t->next;
      t->next = d->next;
    }
  else
    {
      while (t->next->next != NULL)
	t = t->next;
      t->next = NULL;
    }
}
void print_list(link *t)
{
  if (t->item)
    while (t != NULL)
    {
      if (t->item)
	printf("%d ", t->item);
      t = t->next;
    }
  else
    printf("Empty list");
  printf("\n");
}
