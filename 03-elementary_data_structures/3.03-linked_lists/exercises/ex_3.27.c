#include <stdio.h>
#include <stdlib.h>

typedef struct node* link;
struct node 
{
  int item;
  link next;
};

link generate_circular_list(int, int);
void print_list(link);
void move_node(link, link);

int main(void)
{
  link l, x, t;
  int n, m, i;

  printf("Enter the length and starting no of the 1st list: ");
  scanf("%d %d", &n, &m);
  l = malloc(sizeof(link));
  if (l != NULL)
    l = generate_circular_list(n, m);
  print_list(l);
  t = l;
  x = l;
  for (i = 0; i < 2; i++)
    t = t->next;
  for (i = 0; i < 5; i++)
    x = x->next;
  move_node(x, t);
  print_list(l);
  return 0;
}

link generate_circular_list(int len, int start)
{
  link t, head;
  int i;

  t = malloc(sizeof(link));
  if (t != NULL)
    {
      t->item = start;
      t->next = t;
      head = t;
    }
  for (i = 1; i < len; i++)
    {
      t = (t->next = (malloc(sizeof(link))));
      if (t != NULL)
	{
	  t->item = start + i;
	  t->next = head;
	}
    }
  return head;
}

void print_list(link t)
{
  link start = t;

  printf("%d ", t->item);
  t = t->next;
  while(t != start)
    {
      printf("%d ", t->item);
      t = t->next;
    }
  printf("\n");
}

void move_node (link x, link t)
{
  link nod = t->next, h = x->next;

  t->next = t->next->next;
  x->next = nod;
  nod->next = h;
}
