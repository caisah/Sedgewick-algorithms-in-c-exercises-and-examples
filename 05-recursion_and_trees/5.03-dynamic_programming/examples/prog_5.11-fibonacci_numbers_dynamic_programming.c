#include <stdio.h> 

#define N 10

int knownF[N];
int unknown;

int F(int i)
{
  int t;

  if (knownF[i] != unknown)
    return knownF[i];
  if (i == 0)
    t = 0;
  if (i == 1)
    t = 1;
  if (i > 1)
    t = F(i-1) + F(i-2);
  return knownF[i] = t;
}

int main(void) 
{
  int i;

  unknown = -1;
  for (i = 0; i < N; i++)
    knownF[i] = unknown;
  printf("%d\n", F(N));
  return 0;
}
