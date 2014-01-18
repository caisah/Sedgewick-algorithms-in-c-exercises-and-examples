#ifndef LIST_H
#define LIST_H

typedef struct node *link;
struct node
{
  int v;
  link next;
};
link new(int, link);

#endif


