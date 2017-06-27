#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

char *str_cat(char *s1, char *s2)
{
  char *res, *head;
  int i = 0, j;

  res = malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
  head = res;
  if (res != NULL)
    {
      while (s1[i] != '\0')
	*res++ = s1[i++];
      j = i;
      i = 0;
      while(s2[i] != '\0')
	*res++ = s2[i++];
      res[j] = '\0';
    }
  return head;
}

char *str_cpy(char *s)
{
  char *res, *head;

  res = malloc((strlen(s) + 1) * sizeof(char));
  head = res;
  if (res != NULL)
    while (*res++ = *s++);
  return head;
}

int main(void) 
{
  char s1[N], s2[N], *res;
  int len;

  printf("Enter a string: ");
  scanf("%s", s1);
  printf("Enter the second string: ");
  scanf("%s", s2);
  res = str_cpy(s1);
  printf("\nThe copied string: %s\n", res);
  res = str_cat(s1, s2);
  printf("The concatenated strings: %s\n", res);
  return 0;
}
