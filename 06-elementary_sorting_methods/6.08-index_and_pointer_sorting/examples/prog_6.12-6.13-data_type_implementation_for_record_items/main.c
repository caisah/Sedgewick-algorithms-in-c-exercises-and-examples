#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "array.h"

#define maxN 100

int less(Item a, Item b)
{
  return a->num < b->num;
}
void sort(Item a[], int l, int r)
{
  int i, j;
  for (i = l+1; i <= r; i++)
    for (j = i; j > l; j--)
      compexch(a[j-1], a[j]);
}

int main(int argc, char *argv[]) 
{
  int N;
  Item *a;

  printf("Enter records: \n");
  a = malloc (maxN*sizeof(Item));
  scaninit(a, &N);
  printf("\nInitial: \n");
  show(a, 0, N-1);
  sort(a, 0, N-1);
  printf("Sorted: \n");
  show(a, 0, N-1);
  return 0;
}
