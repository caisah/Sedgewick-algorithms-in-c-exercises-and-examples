#include <stdlib.h>
#include "stack.h"

static c_link c_head;

c_link c_new(char item, c_link next)
{
  c_link x = malloc(sizeof *x);

  x->item = item;
  x->next = next;
  return x;
}

void cSTACKinit(void)
{
  c_head = NULL;
}

int cSTACKempty(void)
{
  return c_head == NULL;
}

void cSTACKpush(char item)
{
  c_head = c_new(item, c_head);
}

char cSTACKpop()
{
  char item = c_head->item;
  c_link t = c_head->next;

  free(c_head);
  c_head = t;
  return item;
}


static i_link i_head;

i_link i_new(int item, i_link next)
{
  i_link x = malloc(sizeof *x);

  x->item = item;
  x->next = next;
  return x;
}

void iSTACKinit(void)
{
  i_head = NULL;
}

int iSTACKempty(void)
{
  return i_head == NULL;
}

void iSTACKpush(int item)
{
  i_head = i_new(item, i_head);
}

int iSTACKpop()
{
  char item = i_head->item;
  i_link t = i_head->next;

  free(i_head);
  i_head = t;
  return item;
}
