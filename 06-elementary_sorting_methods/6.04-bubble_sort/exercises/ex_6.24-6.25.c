#include <stdio.h> 
#include <stdlib.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define compexch(A, B) if (less(B, A)) exch(A, B)

void bubble(Item a[], int l, int r)
{
  int i, j, passes = 0;

  for (i = l; i < r; i++)
    for (j = r;  j > i; j--)
      {
	passes++;
	compexch(a[j-1], a[j]);
      }
  printf("\nPasses: %d\n", passes);
}
  
void bubble_improved(Item a[], int l, int r)
{
  int i, j, ex, passes = 0;

  for (i = l; i < r; i++)
    {
      ex = 0;
    for (j = r;  j > i; j--)
      {
	passes++;
	if (less (a[j], a[j-1]))
	  {
	    ex++;
	    exch(a[j], a[j-1]);
	  }
      }
    if (!ex)
      break;
    }
  printf("\nPasses: %d\n", passes);
}

int main(int argc, char *argv[]) 
{
  int i, N = 10;
  int a[] = {4, 2, 1, 5, 2, 10, 11, 12, 13, 14};
  int b[] = {4, 2, 1, 5, 2, 10, 11, 12, 13, 14};
  
  printf("Initial: ");
  for (i = 0; i < N; i++)
    printf("%d ", a[i]);
  printf("\nNormal bubble: ");
  bubble(a, 0, N);
  for (i = 0; i < N; i++)
    printf("%d ", a[i]);
  printf("\nImproved bubble: ");
  bubble_improved(b, 0, N);
  for (i = 0; i < N; i++)
    printf("%d ", b[i]);
  printf("\n");
  return 0;
}
