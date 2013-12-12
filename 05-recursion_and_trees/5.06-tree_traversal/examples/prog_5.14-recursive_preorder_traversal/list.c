#include <stdio.h> 
#include <stdlib.h>
#include "item.h"
#include "list.h"

link new_node(Item item)
{
  link t = malloc(sizeof(link));

  t->item = item;
  t->r = t->l = NULL;
  return t;
}

void add_left_leaf(link parent, Item item)
{
  parent->l = new_node(item);
}

void add_right_leaf(link parent, Item item)
{
  parent->r = new_node(item);
}
