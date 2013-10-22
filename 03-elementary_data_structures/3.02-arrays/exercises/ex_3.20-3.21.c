#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 32
#define M 1000

int heads(int p)
{
  return rand() < RAND_MAX * (p/N);
}

int main(void)
{
  int i, j, cnt, p;
  int *f = malloc((N+1) * sizeof(int));

  srand(time(NULL));
  printf("Enter the probability p: ");
  scanf("%d", &p);
  for(i = 0; i <= N; i++)
    f[i] = 0;
  for(i = 0; i < M; i++, f[cnt]++)
    for (cnt = 0, j = 0; j <= N; j++)
      if (heads(p))
	cnt++;
  for (j = 0; j <= N; j++)
    {
      printf("%2d ", j);
      for (i = 0; i < f[j]; i+=10)
	printf("*");
      printf("\n");
    }
  return 0;
}
