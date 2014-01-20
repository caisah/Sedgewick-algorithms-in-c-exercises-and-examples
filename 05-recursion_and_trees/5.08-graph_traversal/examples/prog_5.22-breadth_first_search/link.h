#ifndef LINK_H
#define LINK_H

typedef struct node *link;
struct node
{
  int v;
  link next;
};
link new_node(int, link);

#endif


