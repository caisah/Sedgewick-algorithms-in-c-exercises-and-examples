#include <stdio.h> 

int factorial(int n, int m)
{
  if (n == 0)
    return 1;
  return ((factorial(n-1, m) % m) * (n % m));
}

int main(void) 
{
  printf("%d\n", factorial(100000, 997));
  
  return 0;
}
