#include <stdio.h>
#include <stdlib.h>

#define N 30

typedef struct node* link;
struct node
{
  int item;
  link next;
};

int nodes_in_between(link, link);

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
  new = start;
  for (i = 0; i < 5; i++)
    new = new->next;
  printf("Number of nodes: %d\n", nodes_in_between(start, new));
  return 0;
}

int nodes_in_between(link start, link end)
{
  int i = 0;

  while (start != end)
    {
      i++;
      start = start->next;
    }
  return i;
}
