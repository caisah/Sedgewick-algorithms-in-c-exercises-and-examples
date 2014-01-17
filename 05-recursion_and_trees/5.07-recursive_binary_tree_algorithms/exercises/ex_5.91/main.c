#include <stdlib.h>
#include <stdio.h> 
#include "item.h"
#include "list.h"

#define MAX_VAL 100

/*
                10
               /  \
              /    \
	     /      \
            10       9
           / \      / \
	  /   \    9   3
        10     9        
       / \    / \        
      10  3  2   9	 
*/

int min(int a, int b)
{
  return ((a > b) ? b : a);
}

int has_children(link x)
{
  return (x->r != NULL || x->l != NULL);
}

/* other_value: returns the first value diffrent from val traversing 
                down the tournament x */
Item other_value(link x, Item val)
{
  link u, v, next = NULL;

  if (x == NULL)
    return -1;
  else
    {
      u = x->l;
      v = x->l;
    }
  if (u != NULL)
    if (u->item != val)
      return u->item;
    else
      next = u;
  if (v != NULL)
    if (v->item != val)
      return v->item;
    else
      next = v;
  return other_value(next, val);
}
link remove_leaf(link x)
{
  free(x);
  return NULL;
}

void rem(link x, Item val)
{
  link u, v;
      
  if ((u = x->l) != NULL)
    {
      if (!has_children(u))
	{
	  if (u->item == val)
	    x->l = remove_leaf(u);
	}
      else
	{
	  if (u->item == val)
	    u->item = other_value(u, val);
	  rem(u, val);
	}
    }
  if ((v = x->r) != NULL)
    {
      if (!has_children(u))
	{
	  if (v->item == val)
	    x->r = remove_leaf(v);
	}
      else
	{
	  if (v->item == val)
	    v->item = other_value(v, val);
	  rem(v, val);
	}
    }
  return;
}

void printnode(int c, int h)
{
  int i;

  for (i = 0; i < h; i++)
    printf("   ");

    printf("%d\n", c);
}

void show(link x, int h)
{
  if (x == NULL)
    {
      printnode(-1, h);
      return;
    }
  show(x->l, h+3);
  printnode(x->item, h);
  show(x->r, h+3);
}

int main(void) 
{
  link root;
  
  root = new_node(10);
  add_left_leaf(root, 10);
  add_left_leaf(root->l, 10);
  add_right_leaf(root->l, 9);
  add_left_leaf(root->l->l, 10);
  add_right_leaf(root->l->l, 3);
  add_left_leaf(root->l->r, 2);
  add_right_leaf(root->l->r, 9);
  add_right_leaf(root, 9);
  add_left_leaf(root->r, 9);
  add_right_leaf(root->r, 3);
  /* add_left_leaf(root, 9); */
  /* add_right_leaf(root, 10); */
  rem(root, 9);
  show(root, 1);
  return 0;
}
