#include <stdio.h> 

int gcd(int x, int y)
{
  int temp;
  
  while (y != 0)
    {
      temp = y;
      y = x % y;
      x = temp;
    }
  return x;
}

int main(void) 
{
  printf("%d\n", gcd(27, 18));
}
