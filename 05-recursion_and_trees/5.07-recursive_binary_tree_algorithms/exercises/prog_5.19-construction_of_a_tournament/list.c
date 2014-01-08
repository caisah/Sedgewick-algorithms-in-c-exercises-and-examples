#include <stdio.h> 
#include <stdlib.h>
#include "item.h"
#include "list.h"

link new_node(Item item, link l, link r)
{
  link x = malloc(sizeof(link));

  x->item = item;
  x->r = r;
  x->l = l;
  return x;
}

link max(Item a[], int l, int r)
{
  int m = (l+r) / 2;
  Item u, v;
  link x = new_node(a[m], NULL, NULL);

  if (l == r)
    return x;
  x->l = max(a, l, m);
  x->r = max(a, m+1, r);
  u = x->l->item;
  v = x->r->item;
  if (u > v)
    x->item = u;
  else
    x->item = v;
  return x;
}
