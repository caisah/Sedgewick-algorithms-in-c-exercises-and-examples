#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "array.h"

void sort(Item a[], int l, int r)
{
  int i, j;
  for (i = l+1; i <= r; i++)
    for (j = i; j > l; j--)
      compexch(a[j-1], a[j]);
}

int main(int argc, char *argv[]) 
{
  int N, sw;
  Item *a;

  srand(time(NULL));
  if (argc < 3)
    printf("You have not entered enough arguments: N and sw required!\n ");
  else
    {
      N = atoi(argv[1]);
      sw = atoi(argv[2]);
      a = malloc(N*sizeof(Item));
      if (sw)
	randinit(a, N);
      else
	scaninit(a, &N);
      printf("Initial: ");
      show(a, 0, N-1);
      sort(a, 0, N-1);
      printf("Sorted: ");
      show(a, 0, N-1);
    }
  return 0;
}
