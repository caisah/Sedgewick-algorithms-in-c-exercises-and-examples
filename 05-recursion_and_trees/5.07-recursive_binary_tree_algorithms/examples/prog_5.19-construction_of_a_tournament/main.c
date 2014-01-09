#include <stdlib.h>
#include <stdio.h> 
#include "item.h"
#include "list.h"

/*
                E
              /   \
	     /     \
            D       H
           / \     / \
          B       F
         / \     / \
        A   C       G
       / \ / \     / \

*/

void printnode(char c, int h)
{
  int i;

  for (i = 0; i < h; i++)
    printf("   ");
  printf("%c\n", c);
}

void show(link x, int h)
{
  if (x == NULL)
    {
      printnode('*', h);
      return;
    }
  show(x->r, h+1);
  printnode(x->item, h);
  show(x->l, h+1);
}

int main(void) 
{
  Item a[] = {'A', 'M', 'P', 'L', 'E'};
  link root;
  
  root = max(a, 0, 4);
  show(root, 1);
  return 0;
}
