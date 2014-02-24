#include <stdio.h>
#include <stdlib.h> 
#include "list.h"

#define key(A) (A)
#define less(A, B) (key(A) < key(B))

link merge(link a, link b)
{
  struct node head;
  link c = &head;

  while ((a != NULL) && (b != NULL))
    if (less(a->item, b->item))
      {
	c->next = a;
	c = a;
	a = a->next;
      }
    else
      {
	c->next = b;
	c = b;
	b = b->next;
      }
  c->next = (a == NULL) ? b : a;
  return head.next;
}

link mergesort(link c)
{
  link a, b;

  if (c == NULL || c->next == NULL)
    return c;
  a = c;
  b = c->next;
  while ((b != NULL) && (b->next != NULL))
    {
      c = c->next;
      b = b->next->next;
    }
  b = c->next;
  c->next = NULL;
  return merge(mergesort(a), mergesort(b));
}

int main(int argc, char *argv[]) 
{
  int N;
  link a;

  if (argc < 2)
    printf("You have not entered enough arguments: N required!\n ");
  else
    {
      N = atoi(argv[1]);
      a = init(N);
      printf("Before: ");
      print_list(a);
      printf("After: ");
      print_list(mergesort(a));
    }
  return 0;
}
