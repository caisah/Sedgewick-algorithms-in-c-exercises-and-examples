#ifndef LIST_H
#define LIST_H

#include "item.h"
typedef struct tnode *link;
extern char a[];
struct tnode
{
  char token;
  link l, r;
};

link new(char, link, link);
link parse(void);
#endif
