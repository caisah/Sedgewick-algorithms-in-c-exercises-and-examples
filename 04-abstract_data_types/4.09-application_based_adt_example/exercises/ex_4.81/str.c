#include <stdio.h>
#include <stdlib.h> 
#include "str.h"

struct String
{
  int len;
  char *s;
};

void str_destroy(str s)
{
  free(s->s);
  free(s);
}

str str_create(char *a)
{
  int i = 0, n = 0;
  str s = malloc(sizeof(str));

  while (a[i++] != '\0')
    n++;
  s->len = n;
  s->s = malloc( (n+1) * sizeof(char));
  for (i = 0; i < n; i++)
    s->s[i] = a[i];
  s->s[i] = '\0';
  return s;
}

int str_len(str s)
{
  return s->len;
}

int str_comp(str s1, str s2)
{
  int i = 0;

  while ((s1->s[i] != '\0') && (s2->s[i] != '\0'))
    {
      if (s1->s[i] > s2->s[i])
	return 1;
      if (s1->s[i] < s2->s[i])
	return -1;
      i++;
    }
  if (s1->len == s2->len)
    return 0;
  else
    return (s1->len > s2->len) ? 1 : -1;
}  

str str_copy(str dest, str source)
{
  str_destroy(dest);
  dest = str_create(source->s);
  return dest;
}

str str_concat(str s1, str s2)
{
  str s = malloc(sizeof(str));
  int i, j = 0;

  s->len = s1->len + s2->len;
  s->s = malloc( (s->len+1) * sizeof(char));
  for (i = 0; s1->s[i] != '\0'; i++)
    s->s[j++] = s1->s[i];
  for (i = 0; s2->s[i] != '\0'; i++)
    s->s[j++] = s2->s[i];
  s->s[j] = '\0';
  return s;  
}
void str_print(str s)
{
  int i = 0;

  for (i = 0; s->s[i] != '\0'; i++)
    printf("%c", s->s[i]);
}
