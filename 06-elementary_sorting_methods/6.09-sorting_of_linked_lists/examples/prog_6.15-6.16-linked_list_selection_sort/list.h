#ifndef LIST_H
#define LIST_H

typedef int Item;
typedef struct node *link;
struct node
{
  Item item;
  link next;
};

link new(Item, link);
link init(int);
void show(link);
link sort(link);

#endif
