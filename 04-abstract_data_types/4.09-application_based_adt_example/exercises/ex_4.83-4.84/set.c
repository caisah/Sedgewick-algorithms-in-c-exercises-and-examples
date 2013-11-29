#include <stdio.h>
#include <stdlib.h> 
#include "set.h"

struct Set 
{
  int *elem;
  int len;
};

set set_init(int m)
{
  set s = malloc(sizeof(set));
  int i;

  s->len = m;
  s->elem = malloc(m*sizeof(int));
  for (i = 0; i < m; i++)
    s->elem[i] = 0;
  return s;
}

void set_add(set s, int elem)
{
  if (elem < s->len)
    s->elem[elem] = 1;
  else
    {
      printf("Wrong value! Create different set.");
      exit(-1);
    }
}
void set_print(set s)
{
  int i;

  for (i = 0; i < s->len; i++)
    if (s->elem[i])
      printf("%d ", i);
}  

set set_union(set s1, set s2)
{
  int i, max;
  set s;
  
  max = (s1->len > s2->len) ? s1->len : s2->len;
  s = set_init(max);
  for (i = 0; i < s1->len; i++)
    if (s1->elem[i])
      set_add(s, s1->elem[i]);
  for (i = 0; i < s2->len; i++)
    if (s2->elem[i])
      set_add(s, i);
  return s;
}

set set_intersection(set s1, set s2)
{
  int i, min;
  set s;

  min = (s1->len < s2->len) ? s1->len : s2->len;
  s = set_init(min);
  for (i = 0; i < min; i++)
    if (s1->elem[i] && s2->elem[i])
      set_add(s, i);
  return s;
}

set set_complement(set s)
{
  int i;
  set t;

  t = set_init(s->len);
  for (i = 0; i < s->len; i++)
    if (s->elem[i] == 0)
      set_add(t, i);
  return t;
}
