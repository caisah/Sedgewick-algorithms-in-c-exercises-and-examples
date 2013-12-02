#include <stdio.h> 
#include <stdlib.h>
#include "item.h"
#include "list.h"

link new(Item item)
{
  link t = malloc(sizeof(link));

  t->item = item;
  t->next = NULL;
  return t;
}

link list_init(Item item)
{
  return new(item);
}

void list_insert_next(link last, Item item)
{
  last->next = new(item);
}

void list_print(link t)
{
  while (t != NULL)
    {
      print_item(t->item);
      t = t->next;
    }
}

