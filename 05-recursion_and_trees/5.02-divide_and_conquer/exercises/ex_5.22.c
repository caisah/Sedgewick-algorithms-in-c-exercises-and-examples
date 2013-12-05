#include <stdio.h> 

#define N 8  // power of 2
#define I 6   // i-th mark

int a[N];

int rule(int l, int r, int h, int k)
{
  int m = (l+r)/2;

  if (h > 0)
    {
      rule(l, m, h-1, k);
      if (m == k)
      	return h;
      rule(m, r, h-1, k);
    }
}

int main(void) 
{
  int l = 0, r = N, h = (l+r)/2-1;

  printf("%d\n", rule(l, r, h, I));
}
