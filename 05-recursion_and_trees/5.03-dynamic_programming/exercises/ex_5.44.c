#include <stdio.h> 

#define N 5

int cache[N+1];

int C(int n, int k)
{
  int i, t = k;

  if (k > 1)
    for (i = 0; i < k; i++)   // calculate C(k)
      t += cache[i];
  else
    switch (k)
      {
      case 0:                // C(0)
	t = 1;
	break;
      case 1:                // C(1)
	t = 3;
	break;
      }
  cache[k] = t;             // add C(k) to cache 
  if (k == n)
    return t;
  else
    return C(n, k+1);
}

int main(void) 
{
  printf("%d\n", C(N, 0));
  return 0;
}
