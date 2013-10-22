#include <stdio.h>

#define MAX 100

int main(void) 
{
  char s[MAX], c;
  int i = 0, j, flag = 0;

  printf("Enter the string: ");
  while ((c = getchar()) != EOF)
    s[i++] = c;
  s[i] = '\0';
  j = i - 1;
  i = 0;
  while (i < j)
    {
      while (s[i] == ' ')
	i++;
      while (s[j] == ' ')
	j--;
      if (s[i] != s[j])
	{
	  flag = 1;
	  break;
	}
      i++;
      j--;
    }
  if (flag)
    printf("\n'%s' is not palindrome\n", s);
  else
    printf("\n'%s' is palindrome\n", s);
  return 0;
}
