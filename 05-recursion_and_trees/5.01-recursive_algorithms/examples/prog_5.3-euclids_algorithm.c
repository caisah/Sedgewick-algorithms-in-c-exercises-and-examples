#include <stdio.h> 

int gcd(int m, int n)
{
  if (n == 0)
    return m;
  return gcd(n, m % n);
}

int main(void) 
{
  printf("%d\n", gcd(20, 10));
  
  return 0;
}
