#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  int i = 0;
  str s = malloc(sizeof(str));

  s->len = strlen(a);
  s->s = malloc( (s->len+1) * sizeof(char));
  for (i = 0; i < s->len; i++)
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
  return strcmp(s1->s, s2->s);
}  

str str_copy(str dest, str source)
{
  strcpy(dest->s, source->s);
  return dest;
}

str str_concat(str s1, str s2)
{
  strcat(s1->s, s2->s);
  return s1;
}
void str_print(str s)
{
  int i = 0;

  for (i = 0; s->s[i] != '\0'; i++)
    printf("%c", s->s[i]);
}
