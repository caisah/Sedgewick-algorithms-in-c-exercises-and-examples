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

int count_leafs(link x)
{
  if (x == NULL)
    return 0;
  if (x->r == NULL && x->l == NULL)
    return 1;
  return (count_leafs(x->l) + count_leafs(x->r));
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

  printf("Number of leafs: %d\n", count_leafs(root));
  return 0;
}
