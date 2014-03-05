#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "item.h"

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}

static Item *pq;
static int N;

void fixUp(Item a[], int k)
{
  while (k > 1 && less(a[k/2], a[k]))
    {
      exch(a[k], a[k/2]);
      k = k/2;
    }
}

void fixDown(Item a[], int k, int N)
{
  int j;

  while (2*k <= N)
    {
      j = 2*k;
      if (j < N && less(a[j], a[j+1]))
	j++;
      if (!less(a[k], a[j]))
	break;
      exch(a[k], a[j]);
      k = j;
    }
}

void PQinit(int maxN)
{
  pq = malloc((maxN+1)*sizeof(Item));
  N = 0;
}

int PQempty(void)
{
  return N == 0;
}

void PQinsert(Item v)
{
  pq[++N] = v;
  fixUp(pq, N);
}

Item PQdelmax(void)
{
  exch(pq[1], pq[N]);
  fixDown(pq, 1, N-1);
  return pq[N--];
}

void heapsort(Item a[], int l, int r)
{
  int k, N = r-l+1;
  Item *pq = a+l-1;

  for (k = N/2; k >= 1; k--)
    fixDown(pq, k, N);
  while (N > 1)
    {
      exch(pq[1], pq[N]);
      fixDown(pq, 1, --N);
    }
  
}

void print_array(Item a[], int n)
{
  int i;

  for (i = 0; i < n; i++)
    {
      printf("%d ", a[i]);
    }
  printf("\n");
}

int main(int argc, char *argv[]) 
{
  int N, i, *a;

  srand(time(NULL));
  if (argc < 2)
    printf("You have not entered enough arguments: N required!\n ");
  else
    {
      N = atoi(argv[1]);
      a = malloc(N * sizeof(Item));
      for (i = 0; i < N; i++)
	a[i] = rand() % 1000;
      printf("Before: ");
      print_array(a, N);
      heapsort(a, 0, N-1);
      printf("After: ");
      print_array(a, N);
    }

  return 0;
}
