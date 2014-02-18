#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define eq(A, B) (!less(A, B) && !less(B, A))

void quicksort(Item a[], int l, int r)     
{
  int i, j, k, p, q;
  Item v;

  if (r <= l)
    return;
  v = a[r];
  i = l-1;
  j = r;
  p = l-1;
  q = r;
  
  for (;;)
    {
      while (less(a[++i], v));
      while (less(v, a[--j]))
	if (j == l)
	  break;
      if (i >= j)
	break;
      exch(a[i], a[j]);
      if (eq(a[i], v))
	{
	  p++;
	  exch(a[p], a[i]);
	}
      if (eq(v, a[j]))
	{
	  q--;
	  exch(a[q], a[j]);
	}
    }
  exch(a[i], a[r]);
  j = i-1;
  i = i+1;
  for (k = l; k < p; k++, j--)
    exch(a[k], a[j]);
  for (k = r-1; k > q; k--, i++)
    exch(a[k], a[i]);
  quicksort(a, l, j);
  quicksort(a, i, r);
}

int main(int argc, char *argv[]) 
{
  int i, N, sw, *a;

  srand(time(NULL));
  if (argc < 3)
    printf("You have not entered enough arguments: N and sw required!\n ");
  else
    {
      N = atoi(argv[1]);
      a = malloc(N*sizeof(int));
      sw = atoi(argv[2]);
      if (sw)
	for (i = 0; i < N; i++)
	  a[i] = rand() % 3;
      else
	while (scanf("%d", &a[N]) == 1)
	  N++;
      printf("Initial: ");
      for(i = 0; i < N; i++)
	printf("%3d ", a[i]);
      quicksort(a, 0, N-1);
      printf("\nAfter: ");
      for(i = 0; i < N; i++)
      	printf("%3d ", a[i]);
      printf("\n");
    }
  return 0;
}
