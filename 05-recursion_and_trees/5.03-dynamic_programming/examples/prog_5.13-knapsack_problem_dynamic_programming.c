#include <stdio.h> 

#define N 5
#define X 17

typedef struct 
{
  int size;
  int val;
} Item;

Item items[N];
int maxKnown[X+1];
int unknown = -1;

int knap(int M)
{
  int i, space, max, maxi, t;

  if (maxKnown[M] != unknown)
    return maxKnown[M];
  for (i = 0, max = 0; i < N; i++)
    if ( (space = M-items[i].size) >= 0)
      if ( (t = knap(space) + items[i].val) > max)
	max = t;
  maxKnown[M] = max;
  return max;
}

int main(void) 
{
  int i;
  
  items[0].size = 3;
  items[0].val = 4;
  items[1].size = 4;
  items[1].val = 5;
  items[2].size = 7;
  items[2].val = 10;
  items[3].size = 8;
  items[3].val = 11;
  items[4].size = 9;
  items[4].val = 13;
  for (i = 0; i <= X; i++)
    maxKnown[i] = unknown;
  printf("%d\n", knap(X));
  return 0;
}
