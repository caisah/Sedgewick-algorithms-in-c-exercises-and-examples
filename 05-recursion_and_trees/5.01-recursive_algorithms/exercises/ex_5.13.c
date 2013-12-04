#include <stdio.h> 
#include <stdlib.h>

#define M 5
#define N 9

int i = 0;

void eliminate_member(int *a, int m)
{
  int j = 0;

  while (j < m)
    if ((i < N) && a[i])
      {
	j++;
	i++;
      }
    else
      i = 0;
  printf("%d ", a[i-1]);
  for (j = i-1; j < N; j++)
    a[j] = a[j+1];
  a[N-1] = 0;
  i--;
}  

int josephus(int *a, int m)
{
  if (a[1] == 0)
    {
      printf("\n");
      return a[0];
    }
  eliminate_member(a, m);
  josephus(a,m);
}

int main(void) 
{
  int i;
  int *a = malloc(N * sizeof(int));
  
  for (i = 0; i < N; i++)
    a[i] = i+1;
  printf("The last standing: %d\n", josephus(a, M));
  return 0;
}
