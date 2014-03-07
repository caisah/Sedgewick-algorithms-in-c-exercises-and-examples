#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

typedef int itemType;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {itemType t = A; A = B; B = t;}
#define compexch(A, B) if (less(B, A)) exch(A, B)

void batchersort(itemType a[], int l, int r)
{
  int i, j, k, p, N = r-l+1;

  for (p = 1; p < N; p += p)
    for (k = p; k > 0; k /= 2)
      for (j = k%p; j+k < N; j += (k+k))
	for (i = 0; i < k; i++)
	  if (j+i+k < N)
	    if ((j+i)/(p+p) == (j+i+k)/(p+p))
	      compexch(a[l+j+i], a[l+j+i+k]);
}

void print_list(int n, int a[])
{
  int i;
  
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main(int argc, char *argv[]) 
{
  int N, i;
  itemType *a;

  srand(time(NULL));
  if (argc != 2)
    printf("Missing argument. Enter a power of 2 number!");
  else
    {
      N = atoi(argv[1]);
      a = malloc(N * sizeof(itemType));
      for (i = 0; i < N; i++)
	a[i] = rand() % 1000;
      printf("Before: ");
      print_list(N, a);
      batchersort(a, 0, N-1);
      printf("After: ");
      print_list(N, a);	
    }
  
  return 0;
}
