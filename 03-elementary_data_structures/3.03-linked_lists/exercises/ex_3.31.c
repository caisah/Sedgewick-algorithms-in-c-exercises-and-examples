#include <stdio.h>
#include <stdlib.h>

#define M 10
#define LIM 1000
typedef struct node* link;

struct node
{
  int item;
  link next;
};

int main() 
{
  int i, j, N;
  link t = malloc(sizeof *t), x = t;

  for (j = 2; j <= LIM; j++)
    {
      N = j;
      t->item = 1; t->next = t;
      for (i = 2; i <= N; i++)
	{
	  x = (x->next = malloc(sizeof *x));
	  x->item = i;
	}
      x->next = t;
      while (x != x->next)
	{
	  for (i = 1; i < M; i++)
	    x = x->next;
	  x->next = x->next->next;
	}
      printf("%4d |",N, x->item);
      for (i = 0; i < x->item; i+=10)
	printf("*");
      printf("\n");
    }
  return 0;
}
