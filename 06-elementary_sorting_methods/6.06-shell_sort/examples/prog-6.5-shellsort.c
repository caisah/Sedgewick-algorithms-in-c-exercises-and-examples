#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define compexch(A, B) if (less(B, A)) exch(A, B)

void sort(Item a[], int l, int r)
{
  int i, j, h;

  for (h = 1; h <= (r-l)/9; h = 3*h+1);
  for ( ; h > 0; h /= 3)
      for (i = l+h; i <= r; i++)
	{
	  int j = i;
	  Item  v = a[i];

	  while (j >= l+h && less(v, a[j-h]))
	    {
	      a[j] = a[j-h];
	      j -= h;
	    }
	  a[j] = v;
	}
}

int main(int argc, char *argv[]) 
{
  int i, N, sw;
  int *a = malloc(N*sizeof(int));

  srand(time(NULL));
  if (argc < 3)
    printf("You have not entered enough arguments: N and sw required!\n ");
  else
    {
      N = atoi(argv[1]);
      sw = atoi(argv[2]);
      if (sw)
	for (i = 0; i < N; i++)
	  a[i] = 1000 * (1.0*rand()/RAND_MAX);
      else
	while (scanf("%d", &a[N]) == 1)
	  N++;
      printf("Initial: ");
      for(i = 0; i < N; i++)
	printf("%3d ", a[i]);
      printf("\nAfter: ");
      sort(a, 0, N-1);
      for(i = 0; i < N; i++)
	printf("%3d ", a[i]);
      printf("\n");
    }
  return 0;
}
