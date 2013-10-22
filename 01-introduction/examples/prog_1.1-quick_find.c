/* QUICK FIND ALGORITHM */

#include <stdio.h>

#define N 1000

int main(void)
{
  int p, q, i, t, id[N];

  for (i = 0; i < N; i++)
    id[i] = i;
  while (scanf("%d %d\n", &p, &q) == 2)
    {
      if (id[p] == id[q])
	continue;
      for (t = id[p], i = 0; i < N; i++)
	if (id[i] == t)
	  id[i] = id[q];
      printf(" %d %d\n", p, q);
    }
  return 0;
}
