#include <stdio.h> 

#define N 5

int factorial(int n)
{
   if (n == 0)
     return 1;
   return n*factorial(n-1);
}

int main(void)
{
  printf("%d\n", factorial(N));
  
  return 0;
}
