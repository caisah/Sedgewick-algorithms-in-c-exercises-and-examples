#ifndef LIST_H
#define LIST_H

#include "item.h"
typedef struct node *link;

struct node
{
  Item item;
  link l, r;
};

link new_node(Item, link, link);
link max(Item[], int l, int r);
#endif
