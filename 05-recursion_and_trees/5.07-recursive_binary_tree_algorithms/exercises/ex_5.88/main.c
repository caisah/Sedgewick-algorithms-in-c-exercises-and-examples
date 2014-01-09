#include <stdlib.h>
#include <stdio.h> 
#include "item.h"
#include "list.h"

/*
  0              A
               /  \
              /    \
	     /      \
  1         B        C
           / \     /   \
  2       D       E     F
         / \     / \   / \
*/

int path_len(link x, int x_level)
{
  link u = x->l, v = x->r;
  int level = x_level + 1;

  if (u == NULL && v == NULL)
    return 0;
  if (u != NULL && v == NULL)
    return level + path_len(u, level);
  if (u == NULL && v != NULL)
    return level + path_len(v , level);
  return path_len(u, level) + path_len(v, level) + 2 * level;
}

int main(void) 
{
  link root;

  root = new_node('A');
  add_left_leaf(root, 'B');
  add_left_leaf(root->l, 'D');
  add_right_leaf(root, 'C');
  add_left_leaf(root->r, 'E');
  add_right_leaf(root->r, 'F');
  printf("Path len: %d\n", path_len(root, 0));
  return 0;
}
