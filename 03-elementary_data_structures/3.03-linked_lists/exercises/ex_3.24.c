#include <stdio.h>
#include <stdlib.h>

#define N 30

typedef struct node* link;
struct node
{
  int item;
  link next;
};

int nodes_no(link);

int main(void) 
{
  link start, t, new;
  int i;

  t = malloc(sizeof(link));
  if (t != NULL)
    {
      t->item = 1;
      t->next = t;
      start = t;
      new = t;
    }
  for (i = 2; i <= N; i++)
    {
      new = (new->next = malloc(sizeof(link)));
      if (new != NULL)
	{
	  new->item = i;
	  new->next = t;
	}
    }
  printf("Number of nodes: %d\n", nodes_no(start));
  return 0;
}

int nodes_no(link t)
{
  link start=t;
  int i = 1;

  t = t->next;
  while (t != start)
    {
      i++;
      t = t->next;
    }
  return i;
}
