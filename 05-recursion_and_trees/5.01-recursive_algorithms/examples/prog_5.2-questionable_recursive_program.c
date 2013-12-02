#include <stdio.h> 

#define N 10

int puzzle(int n)
{
  if (n == 1)
    return 1;
  if (n % 2)
    return puzzle(n/2);
  else
    return puzzle(3*n+1);
}

int main(void) 
{
  printf("%d\n", puzzle(N));
  return 0;
}
