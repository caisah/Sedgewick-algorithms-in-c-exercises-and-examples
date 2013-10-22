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
      t->prev = NULL;
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
	  new->prev = t;
	  t = t->next;
	}
    }
  printf("\n");
  return head;
}

void print_list(link *t)
{
  while (t != NULL)
    {
      printf("%d ", t->item);
      t = t->next;
    }
  printf("\n");
}

