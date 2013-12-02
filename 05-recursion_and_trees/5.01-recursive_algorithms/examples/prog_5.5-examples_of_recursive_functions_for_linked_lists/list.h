#ifndef LIST_H
#define LIST_H

#include "item.h"
typedef struct node *link;

struct node
{
  Item item;
  link next;
};

link list_init(Item);
void list_insert_next(link, Item);
void list_print(link);
  
#endif
