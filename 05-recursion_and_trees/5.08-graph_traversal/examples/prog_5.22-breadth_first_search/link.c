#include <stdlib.h>
#include "link.h"

link new_node(int v, link next)
{
  link x = malloc(sizeof *x);

  x->v = v;
  x->next = next;
  return x;
}
