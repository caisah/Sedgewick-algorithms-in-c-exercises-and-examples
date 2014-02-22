#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define compexch(A, B) if (less(B, A)) exch(A, B)

typedef int Item;

int *aux;

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

void mergeAB(Item c[], Item a[], int n, Item b[], int m)
{
  int i, j, k;

  for (i = 0, j = 0, k = 0; k < m+n; k++)
    {
      if (i == n)
	{
	  c[k] = b[j++];
	  continue;
	}
      if (j == m)
	{
	  c[k] = a[i++];
	  continue;
	}
      c[k] = (less(a[i], b[j])) ? a[i++] : b[j++];
    }
}

void mergesortABr(Item a[], Item b[], int l, int r)
{
  int m = (l+r)/2;

  if (r-l <= 10)
    {
      insertion(a, l, r);
      return;
    }
  mergesortABr(b, a, l, m);
  mergesortABr(b, a, m+1, r);
  mergeAB(a+l, b+l, m-l+1, b+m+1, r-m);
}

void mergesortAB(Item a[], int l, int r)
{
  int i;

  for (i = l; i <= r; i++)
    aux[i] = a[i];
  mergesortABr(a, aux, l, r);
}

print_array(Item a[], int n)
{
  int i;

  for(i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
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
      a = malloc(N*sizeof(Item));
      aux = malloc(N*sizeof(Item));
      sw = atoi(argv[2]);
      if (sw)
	for (i = 0; i < N; i++)
	  a[i] = 1000 * (1.0*rand()/RAND_MAX);
      else
	while (scanf("%d", &a[N]) == 1)
	  N++;
      printf("Initial: ");
      print_array(a, N);
      mergesortAB(a, 0, N-1);
      printf("After: ");
      print_array(a, N);
    }
  return 0;
}
