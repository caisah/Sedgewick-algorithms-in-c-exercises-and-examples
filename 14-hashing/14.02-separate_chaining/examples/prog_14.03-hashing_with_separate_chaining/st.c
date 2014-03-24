#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "st.h"

typedef struct STnode* link;
struct STnode
{
  Item item;
  link next;
};
static link *heads, z;
static int N, M;

int hash(char *v, int M)
{
  int h, a = 31415, b = 27183;

  for (h = 0; *v != '\0'; v++, a = a*b % (M-1))
    h = (a*h + *v) % M;
  return h;
}

int eq(char *a, char *b)
{
  return (strcmp(a, b) == 0);
}

static link NEW(Item item, link next)
{
  link x = malloc(sizeof *x);

  x->item = item;
  x->next = next;
  return x;
}

Item search(link h, Key v)
{
  while (h != z)
    {
      if (eq(key(h->item), v))
	return h->item;
      h = h->next;
    }
  return z->item;
}

void STinit(int max)
{
  int i;
  
  N = 0;
  M = max/5;
  heads = malloc(M*sizeof(link));
  z = NEW(NULLitem, NULL);
  for (i = 0; i < M; i++)
    heads[i] = z;
}

void STinsert(Item item)
{
  int i = hash(key(item), M);

  heads[i] = NEW(item, heads[i]);
  N++;
}

Item STsearch(Key v)
{
  return search(heads[hash(v, M)], v);
}

link delete(link h, Item item)
{
  link l = h, t;

  if (l == z)
    return z;
  if (eq(key(l->item), key(item)))
    {
      free(l->next);
      h = z;
      return h;
    }
  t = l->next;
  while (t != z)
    {
      if (eq(key(t->item), key(item)))
  	{
  	  l->next = t->next;
  	  free(t);
  	  break;
  	}
      t = t->next;
    }
  return h;
}

void STdelete(Item item)
{
  int i = hash(key(item), M);

  heads[i] = delete(heads[i], item);
}
