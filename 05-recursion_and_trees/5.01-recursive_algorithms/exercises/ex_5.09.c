#include <stdio.h>
#include <string.h>

char *a = "5 3 + 1 1 + +";
char *b = "2 3 4 + +"
int i = 4;

void clear_spaces(void)
{
  while (a[i] == ' ')
    i++;
}

int prev_term(int j)
{
  int count = 0;
  
  while (dig(a[j]) >= 0)
    {
      j--;
      
    }
  return a[j];
}
int eval()
{
 
}     
int main(void) 
{
  printf("%d\n", eval());
  
  return 0;
}
