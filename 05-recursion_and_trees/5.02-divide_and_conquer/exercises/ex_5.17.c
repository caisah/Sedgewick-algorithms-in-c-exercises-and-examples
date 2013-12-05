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

link create_list(int n)
{
  link head;
  
  if (n == 1)
    {
      head = malloc(sizeof(link));
      head->item = rand() % (2*N+1);
      head->next = NULL;
      return head;
    }
  head = malloc(sizeof(link));
  head->item = rand() % (2*N+1);
  head->next = create_list(n-1);
  return head;
}  

void print_list(link t)
{
  if (t == NULL)
    return;
  printf("%d ", t->item);
  print_list(t->next);
}

int max(link t)
{
  int m;
  
  if (t->next == NULL)
    return t->item;
  return (m = max(t->next)) > t->item ? m : t->item;
}
int main(void)
{
  link head;
  
  srand(time(NULL));
  head = create_list(N);
  print_list(head);
  printf("\n%d\n", max(head));
}  
