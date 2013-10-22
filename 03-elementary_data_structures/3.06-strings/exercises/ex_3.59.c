#include <stdio.h>
#include <string.h>

#define N 100

int main(int argc, char *argv[]) 
{
  char *s = argv[1], c;
  char str[N], word[N];
  int i = 0, j = 0, k = 0, l = 0;

  printf("Enter the string to be searched: ");
  while ((c = getchar()) != EOF)
    str[i++] = c;
  str[i] = '\0';
  i = 0;
  printf("\n");

  while (str[i] != '\0')
    {
      while (str[i] != ' ' && str[i] != '\0')
  	word[j++] = str[i++];
      word[j] = '\0';
      if (strstr(s, word) != NULL)
  	printf("%s\n", word);
      if (str[i] != '\0')
  	i++;
      j = 0;
    }
  return 0;
}
