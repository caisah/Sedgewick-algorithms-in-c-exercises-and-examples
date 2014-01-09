#include <stdlib.h>
#include <stdio.h> 
#include "item.h"
#include "list.h"

/*
                 A
               /  \
              /    \
	     /      \
            B        C
           / \     /   \
          D       E     F
         / \     / \   / \
        G       H   I
       / \     / \ / \
      J   K
     / \ / \
            L
	   / \
*/

int has_children(link x)
{
  if ((x->r != NULL) || (x->l != NULL))
    return 1;
  return 0;		 
}

int count(link x)
{
  link u = x->l, v = x->r;

  if (u == NULL && v == NULL)
    return 0;
  if (u != NULL && v == NULL)
    return count(u);
  if (u == NULL && v != NULL)
    return count(v);
  if (has_children(u) && !has_children(v))
    return 1 + count(u);
  if (has_children(v) && !has_children(u))
    return 1 + count(v);
  return count(u) + count(v);
}  

int main(void) 
{
  link root;

  root = new_node('A');
  add_left_leaf(root, 'B');
  add_left_leaf(root->l, 'D');
  add_left_leaf(root->l->l, 'G');
  add_left_leaf(root->l->l->l, 'J');
  add_right_leaf(root->l->l->l, 'K');
  add_right_leaf(root->l->l->l->r, 'L');
  add_right_leaf(root, 'C');
  add_left_leaf(root->r, 'E');
  add_right_leaf(root->r, 'F');
  add_left_leaf(root->r->l, 'H');
  add_right_leaf(root->r->l, 'I');
  printf("Root has: %d\n", count(root));
  return 0;
}
