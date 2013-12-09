#include <stdio.h> 

#define N 10
#define M 5

int knownF[N];
int unknown;

int F(int i, int m, int last)
{
  int t;

  if (knownF[i] != unknown)
    return knownF[i];
  if (i == 0)
    t = 0;
  if (i == 1)
    t = 1;
  if (i > 1)
    t = F(i-1, m, last) + F(i-2, m, last);
  if (i != last)
    return knownF[i] = t;
  else
    return knownF[i] = t % m;
}

int main(void) 
{
  int i;

  unknown = -1;
  for (i = 0; i < N; i++)
    knownF[i] = unknown;
  printf("%d\n", F(N, M, N));
  return 0;
}
