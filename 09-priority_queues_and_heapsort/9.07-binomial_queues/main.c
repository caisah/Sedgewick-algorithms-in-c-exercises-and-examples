#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "pqbinomial.h"
#include "item.h"

int main(int argc, char *argv[]) 
{
  int N, M, i;
  Item x;
  PQ q1, q2;

  srand(time(NULL));
  if (argc < 3)
    printf("You have not entered enough arguments: N and Mrequired!\n ");
  else
    {
      N = atoi(argv[1]);
      M = atoi(argv[2]);
      q1 = PQinit();
      q2 = PQinit();

      printf("Creating first queue: ");
      for (i = 0; i < N; i++)
      	{
      	  x = rand() % 1000;
      	  printf("%d ", x);
      	  PQinsert(q1, x);
      	}
      printf("\nCreating the second queue: ");
      for (i = 0; i < M; i++)
      	{
      	  x = rand() % 1000;
      	  printf("%d ", x);
      	  PQinsert(q2, x);
      	}
      printf("\nMax from Q1: %d", PQdelmax(q1));
      printf("\nMax form Q2: %d", PQdelmax(q2));
      printf("\nMerged queues: ");
      PQjoin(q1, q2);
      while (!PQempty(q1))
      	printf("%d ", PQdelmax(q1));
      printf("\n");
    }
  return 0;
}
