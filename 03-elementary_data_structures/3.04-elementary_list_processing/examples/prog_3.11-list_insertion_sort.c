#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

typedef struct node *link;
struct node 
{
  int item;
  link next;
};

void print_list(link);

int main(void) 
{
  struct node heada, headb;
  link t, u, x, a, b;
  int i;

  srand(time(NULL));
  heada.item = rand() % 1000;
  heada.next = NULL;
  a = &heada;
  for (i = 0, t = a; i < N-1; i++)
    {
      t->next = malloc(sizeof *t);
      t = t->next;
      t->next = NULL;
      t->item = rand() % 1000;
    }
  print_list(&heada);
  headb.item = heada.item;
  b = &headb;
  b->next = NULL;
  for (t = a->next; t != NULL; t = u)
    {
      u = t->next;
      for (x = b; x->next != NULL; x = x->next)
  	if (x->next->item > t->item)
  	  break;
      t->next = x->next;
      x->next = t;
    }
  print_list(&headb);
}

void print_list(link t)
{
  while (t != NULL)
    {
      printf("%d ", t->item);
      t = t->next;
    }
  printf("\n");
}

