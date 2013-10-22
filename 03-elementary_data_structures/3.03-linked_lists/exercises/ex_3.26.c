#include <stdio.h>
#include <stdlib.h>

typedef struct node* link;
struct node 
{
  int item;
  link next;
};

link generate_circular_list(int, int);
void join_lists(link, link);
void print_list(link);


int main(void)
{
  link l1, l2, l;
  int n1, n2, m1, m2;

  printf("Enter the length and starting no of the 1st list: ");
  scanf("%d %d", &n1, &m1);
  printf("Enter the lenght and starting no of the 2nd list: ");
  scanf("%d %d", &n2, &m2);
  l1 = malloc(sizeof(link));
  if (l1 != NULL)
    l1 = generate_circular_list(n1, m1);
  l2 = malloc(sizeof(link));
  if (l2 != NULL)
    l2 = generate_circular_list(n2, m2);
  l = malloc(sizeof(link));
  print_list(l1);
  print_list(l2);
  join_lists(l1, l2);
  print_list(l1);
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

void join_lists(link l1, link l2)
{
  link s1 = l1, s2 = l2, s11;

  while (l1->next != s1)
    l1 = l1->next;
  l1->next = l2;
  while (l2->next != s2)
    l2 = l2->next;
  l2->next = s1;
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
