#include <stdio.h> 

int i = 0;
char *a = "((1 + 1) + ((2 + 2) + (3 + 3)))";
  
void clear_spaces()
{
  while (a[i] == ' ')
    i++;
}

int get_elem()
{
  int x = 0;

  clear_spaces();
  if (a[i] == '(')
    {
      return eval();
    }
  else
    while ((a[i] >= '0') && (a[i] <= '9'))
      x = 10*x + (a[i++]-'0');
  i++;
  clear_spaces();
  return x;		
}

int eval()
{
  int x, y;
  
  if (a[i] == '(')
    {
      i++;
      x = get_elem();
    }
  if (a[i] == '+')
    {
      i++;
      y = get_elem();
      return x + y;
    }
}

int main(void) 
{
  printf("%d\n", eval());
  
  return 0;
}
