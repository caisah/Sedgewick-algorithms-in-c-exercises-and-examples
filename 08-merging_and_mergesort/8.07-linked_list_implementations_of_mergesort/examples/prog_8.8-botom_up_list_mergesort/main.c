#include <stdio.h>
#include <stdlib.h> 
#include "list.h"
#include "queue.h"

#define key(A) (A)
#define less(A, B) (key(A) < key(B))

int N;

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

link mergesort(link t)
{
  link u;

  for (QUEUEinit(N); t != NULL; t = u)
    {
      u = t->next;
      t->next = NULL;
      QUEUEput(t);
    }
  t = QUEUEget();
  while (!QUEUEempty())
    {
      QUEUEput(t);
      t = merge(QUEUEget(), QUEUEget());
    }
  return t;
}

int main(int argc, char *argv[]) 
{
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
