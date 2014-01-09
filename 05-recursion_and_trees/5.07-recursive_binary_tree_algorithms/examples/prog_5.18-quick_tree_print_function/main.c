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
  link root, left, right;

  root = new_node('E');
  add_left_leaf(root, 'D');
  add_right_leaf(root, 'H');
  left = root->l;
  add_left_leaf(left, 'B');
  left = left->l;
  add_left_leaf(left, 'A');
  add_right_leaf(left, 'C');
  right = root->r;
  add_left_leaf(right, 'F');
  right = right->l;
  add_right_leaf(right, 'G');

  show(root, 1);
  return 0;
}
