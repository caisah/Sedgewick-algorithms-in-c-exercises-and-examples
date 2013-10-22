#include <stdio.h>

#define N 1000

int main(void) 
{
  int i, j, a[N], count=0;

  for (i = 2; i < N; i++)
    a[i] = 1;
  for(i = 2; i < N; i++)
    if (a[i])
      for (j = i; i*j < N; j++)
	a[i*j] = 0;
  for (i = 2; i < N; i++)
    {
      if (a[i])
	count++;
      printf("%d ", i);
      for (j = 0; j < count; j += 5)
	printf("*");
      printf("\n");
    }
  printf("\n");
  
  return 0;
}
