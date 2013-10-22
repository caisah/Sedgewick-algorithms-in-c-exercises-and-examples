/* QUICK UNION ALGORITHM */

#include <stdio.h>

#define N 1000

int main(void)
{
  int p, q, i, j, id[N];

  for (i = 0; i < N; i++)
    id[i] = i;
  while (scanf("%d %d\n", &p, &q) == 2)
    {
      for (i = p; i != id[i]; i = id[i]);
      for (j = q; j != id[j]; j = id[j]);
      if (i == j)
	continue;
      id[i] = j;
      printf(" %d %d\n", p, q);
    }
  return 0;
}
