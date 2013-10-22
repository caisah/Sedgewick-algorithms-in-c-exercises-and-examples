#include <stdio.h>

#define N 100

int main(void)
{
  char s[N], c, res[N];
  int i = 0, j = 0;

  printf("Enter the string: ");
  while ((c = getchar()) != EOF)
    s[i++] = c;
  s[i] = '\0';
  i = 0;
  while (s[i] != '\0')
    {
      res[j++] = s[i++];
      if (s[i] == ' ')
	{
	  res[j++] = s[i++];
	  while (s[i] == ' ')
	    i++;
	}
    }
  res[j] = '\0';
  printf("\n%s\n", res);
  return 0;
}
