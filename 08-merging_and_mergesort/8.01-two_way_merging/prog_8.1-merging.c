#include <stdio.h> 
#include <stdlib.h> 

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
typedef int Item;

#define N 4
#define M 6
int a[] = {1, 4, 14, 30}, b[] = {2, 3, 4, 10, 18, 40};


void merge(Item c[], Item a[], int n, Item b[], int m)
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

print_array(Item a[], int n)
{
  int i;

  for(i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main(void) 
{
  int *c = malloc((N+M) * (sizeof(Item)));

  printf("Arrays: \n");
  print_array(a, N);
  print_array(b, M);
  merge(c, a, N, b, M);
  printf("Merged: \n");
  print_array(c, M+N);
  return 0;
}
