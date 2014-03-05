#include <stdlib.h> 
#include "item.h"
#include "pqfull.h"

struct PQnode
{
  Item key;
  PQlink prev, next;
};

struct pq
{
  PQlink head, tail;
};

PQ PQinit()  
{
  PQ pq = malloc(sizeof(*pq));
  PQlink h = malloc(sizeof(*h));
  PQlink t = malloc(sizeof(sizeof(*t)));

  h->prev = t;
  h->next = t;
  t->prev = h;
  t->next = h;
  pq->head = h;
  pq->tail = t;
  return pq;
}

int PQempty(PQ pq)
{
  return pq->head->next->next == pq->head;
}

PQlink PQinsert(PQ pq, Item v)
{
  PQlink t = malloc(sizeof(*t));

  t->key = v;
  t->next = pq->head->next;
  t->next->prev = t;
  t->prev = pq->head;
  pq->head->next = t;
  return t;
}

Item PQdelmax(PQ pq)
{
  Item max;
  struct PQnode *t, *x = pq->head->next;

  for (t = x; t->next != pq->head; t = t->next)
    if (t->key > x->key)
      x = t;
  max = x->key;
  x->next->prev = x->prev;
  x->prev->next = x->next;
  free(x);
  return max;
}

void PQchange(PQ pq, PQlink x, Item v)
{
  x->key = v;
}

void PQdelete(PQ pq, PQlink x)
{
  x->next->prev = x->prev;
  x->prev->next = x->next;
  free(x);
}

void PQjoin(PQ a, PQ b)
{
  a->tail->prev->next = b->head->next;
  b->head->next->prev = a->tail->prev;
  a->head->prev = b->tail;
  b->tail->next = a->head;
  free(a->tail);
  free(b->head);
}
