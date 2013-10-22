#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct node *link;
struct node
{
  int item;
  link next;
};

void print_list(link);
link reverse(link);
  
int main(void) 
{
  link t, head;
  int i;

  t = malloc(sizeof(link));
  if (t != NULL)
    {
      t->item = 1;
      t->next = NULL;
    }
  head = t;
  for (i = 2; i < N+1; i++)
    {
      t->next = malloc(sizeof(link));
      if (t->next != NULL)
	{
	  t = t->next;
	  t->item = i;
	  t->next = NULL;
	}
    }
  print_list(head);
  head = reverse(head);
  print_list(head);
  return 0;
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

link reverse(link x)
{
  link t, y = x, r = NULL;

  while (y != NULL)
    {
      t = y->next;
      y->next = r;
      r = y;
      y = t;
    }
  return r;
}
