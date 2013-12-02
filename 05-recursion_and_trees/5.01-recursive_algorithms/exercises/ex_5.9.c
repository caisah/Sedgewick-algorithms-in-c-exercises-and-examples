#include <stdio.h>
#include <string.h>

char *a = "5 5 3 + +";
int i=0;
int res = 0;
int first = 1;

int eval()
{
  if (a[i] == '\0')
    return 0;
  while ((a[i] <= '0') && (a[i]e <= '9'))
    i++;
  
  
}     
int main(void) 
{
  printf("%d\n", eval());
  
  return 0;
}
