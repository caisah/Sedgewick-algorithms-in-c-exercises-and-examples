#include <stdio.h>

#define N 1000

int main(void)
{
  char s[N], c;
  int len, max = 0, i = 0, n = 0, k;

  printf("Enter the string: ");
  while ((c = getchar()) != EOF)
    s[i++] = c;
  s[i] = '\0';
  len = i;
  i = 0;
  while (s[i] != '\0')
    {
      if (s[i] == ' ')
	{
	  n = i;
	  k = 0;
	  while (i < len && s[i] == ' ')
	    {
	      k++;
	      i += k;
	    }
	  i = i - k;
	  while (i < len && s[i] == ' ')
	    i++;
	  n = i - n;
	}
      if (n > max)
	max = n;
      if (i < len)
	i++;
    }
  printf("\nMax num of spaces: %d\n", max);
  return 0;
}
