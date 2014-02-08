#include <stdio.h> 
#include <stdlib.h> 
#include "item.h"
#include "array.h"

void randinit(Item a[], int N)
{
  int i;

  for (i = 0; i < N; i++)
    a[i] = ITEMrand();
}

void scaninit(Item a[], int *N)
{
  int i = 0;

  for (i = 0; i< *N; i++)
    if (ITEMscan(&a[i]) == EOF)
      break;
  *N = i;
}

void show(Item a[], int l, int r)
{
  int i;

  for (i = l; i <= r; i++)
    ITEMshow(a[i]);
  printf("\n");
}
