#include <stdio.h>

#define N 5

int cache[N+1];
int unknown = -1;

int C(int n)
{
  int i, t = n;

  if (cache[n] != unknown)       // if value is cached return
    return cache[n];
  if (n > 1)                     // C(k)
    {
      for (i = n-1; i >= 0; i--)
	t += C(i);               
      return (cache[n] = t);
    }
  if (n == 0)        
    {
      cache[0] = 1;
      return 1;                 // C(0)
    }
  if (n == 1)
    {
      cache[1] = 3;
      return 3;                 // C(1)
    }
}  

int main(void) 
{
  int i;

  for (i = 0; i <= N+1; i++)
    cache[i] = unknown;
  printf("%d\n", C(N));
  return 0;
}
