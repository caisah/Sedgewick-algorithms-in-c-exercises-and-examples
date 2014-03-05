#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "item.h"

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}

static Item *pq;
static int N;

void PQinit(int maxN)
{
  pq = malloc(maxN*sizeof(Item));
  N = 0;
}

int PQempty(void)
{
  return N == 0;
}

void PQinsert(Item v)
{
  pq[N++] = v;
}

Item PQdelmax(void)
{
  int j, max = 0;

  for (j = 1; j < N; j++)
    if (less(pq[max], pq[j]))
      max = j;
  exch(pq[max], pq[N-1]);
  return pq[--N];
}

int main(int argc, char *argv[]) 
{
  int N, i, num;
  int a[] = {88, 3, 149, 498, 999};

  srand(time(NULL));
  if (argc < 2)
    printf("You have not entered enough arguments: N required!\n ");
  else
    {
      N = atoi(argv[1]);
      PQinit(N);
      printf("Insert: ");
      for (i = 0; i < N; i++)
	{
	  num = (rand() % 1001);
	  printf("%d ", num);
	  PQinsert(num);
	}
      printf("\n");
      for (i = 0; i < (sizeof(a)/sizeof(a[0])); i++)
	{
	  printf("Extract: %d ", PQdelmax());
	  printf("Insert: %d\n", a[i]);
	  PQinsert(a[i]);
	}
    }
  printf("Extract: %d\n", PQdelmax());
  return 0;
}
