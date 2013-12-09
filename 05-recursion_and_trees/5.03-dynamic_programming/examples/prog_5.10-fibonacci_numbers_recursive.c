#include <stdio.h> 

#define N 10

int F(int i)
{
  if (i < 1)
    return 0;
  if (i == 1)
    return 1;
  return F(i-1) + F(i-2);
}

int main(void) 
{
  printf("%d\n", F(N));
  
  return 0;
}
