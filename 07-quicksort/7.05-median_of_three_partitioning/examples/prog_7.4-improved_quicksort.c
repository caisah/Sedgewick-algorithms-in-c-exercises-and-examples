#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define compexch(A, B) if (less(B, A)) exch(A, B)

#define M 10

void insertion(Item a[], int l, int r)
{
  int i;

  for (i = r; i > l; i--)
    compexch(a[i-1], a[i]);  // put the smallest into first position
  for (i = l + 2; i <= r; i++)
    {
      int j = i;
      Item v = a[i];
      
      while (less(v, a[j-1]))
	{
	  a[j] = a[j-1];
	  j--;
	}
      a[j] = v;
    }
}

int partition(Item a[], int l, int r)
{
  int i = l-1, j = r;
  Item v = a[r];

  for (;;)
    {
      while (less(a[++i], v));
      while (less(v, a[--j]))
	if (j == l)
	  break;
      if (i >= j)
	break;
      exch(a[i], a[j]);
    }
  exch(a[i], a[r]);
  return i;
}

void quicksort(Item a[], int l, int r)     
{
  int i;

  if (r-l <= M)
    return;
  exch(a[(l+r)/2], a[r-1]);
  compexch(a[l], a[r-1]);
  compexch(a[l], a[r]);
  compexch(a[r-1], a[r]);
  i = partition(a, l+1, r-1);
  quicksort(a, l, i-1);
  quicksort(a, i+1, r);
}

void sort(Item a[], int l, int r)
{
  quicksort(a, l, r);
  insertion(a, l, r);
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
	  a[i] = 1000 * (1.0*rand()/RAND_MAX);
      else
	while (scanf("%d", &a[N]) == 1)
	  N++;
      printf("Initial: ");
      for(i = 0; i < N; i++)
	printf("%3d ", a[i]);
      sort(a, 0, N-1);
      printf("\nAfter: ");
      for(i = 0; i < N; i++)
	printf("%3d ", a[i]);
      printf("\n");
    }
  return 0;
}
