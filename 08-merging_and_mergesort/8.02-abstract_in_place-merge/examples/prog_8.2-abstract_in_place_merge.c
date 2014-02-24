#include <stdio.h> 
#include <stdlib.h> 

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
typedef int Item;

#define N 4
#define M 6
int a[] = {1, 4, 14, 30, 2, 3, 4, 10, 18, 40};
int aux[M+N];

void merge(Item a[], int l, int m, int r)
{
  int i, j, k;

  for (i = m+1; i > l; i--)
    aux[i-1] = a[i-1];
  for (j = m; j < r; j++)
    aux[r+m-j] = a[j+1];
  for (k = l; k <= r; k++)
    if (less(aux[j], aux[i]))
      a[k] = aux[j--];
    else
      a[k] = aux[i++];
}

print_array(Item a[], int n)
{
  int i;

  for(i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main(void) 
{
  printf("Array: \n");
  print_array(a, M+N);
  merge(a, 0, N-1, M+N-1);
  printf("Merged: \n");
  print_array(a, M+N);
  return 0;
}
