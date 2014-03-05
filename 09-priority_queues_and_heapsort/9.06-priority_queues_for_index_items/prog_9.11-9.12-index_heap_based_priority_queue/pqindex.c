#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "pqindex.h"

typedef int Item;

#define maxPQ 100

static int N, pq[maxPQ+1], qp[maxPQ+1];
Item *a;

// this can be changed depending on the input data
int less (int i, int j)
{
  return (a[i] < a[j]);
}

void exch(int i, int j)
{
  int t;

  t = qp[i];
  qp[i] = qp[j];
  qp[j] = t;
  pq[qp[i]] = i;
  pq[qp[j]] = j;
}
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

void PQinit(void)
{
  N = 0;
}

int PQempty(void)
{
  return !N;
}

void PQinsert(int k)
{
  qp[k] = ++N;
  pq[N] = k;
  fixUp(pq, N);
}

int PQdelmax(void)
{
  exch(pq[1], pq[N]);
  fixDown(pq, 1, --N);
  return pq[N+1];
}

void PQchange(int k)
{
  fixUp(pq, qp[k]);
  fixDown(pq, qp[k], N);
}

int main(int argc, char *argv[]) 
{
  int N, i;

  srand(time(NULL));
  if (argc < 2)
    printf("You have not entered enough arguments: N required!\n ");
  else
    {
      N = atoi(argv[1]);
      a = malloc(N * sizeof(Item));
      for (i = 0; i < N; i++)
	a[i] = rand() % 1000;
      printf("Array: ");
      for (i = 0; i < N; i++)
	printf("%d ", a[i]);
      printf("\nCreating queue...");
      for (i = 0; i < N; i++)
	PQinsert(i);
      printf("\nQueue: ");
      while (!PQempty())
	printf("%d ", a[PQdelmax()]);
      printf("\n");
    }
  return 0;
}
