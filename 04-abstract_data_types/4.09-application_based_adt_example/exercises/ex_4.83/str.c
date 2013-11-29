#include <stdio.h>
#include <stdlib.h> 
#include "str.h"

// define link type
typedef struct node *link;
struct node
{
  char item;
  link next;
};

// define String type
struct String
{
  int len;
  link head;
};

void str_destroy(str s)
{
  link t;

  while (s->head != NULL)
    {
      t = s->head;
      s->head = s->head->next;
      free(t);
    }
  free(s);
}

link new(link next, char item)
{
  link t = malloc(sizeof(link));

  t->next = next;
  t->item = item;
  return t;
}

str str_create(char *a)
{
  int i = 0, n = 0;
  str s = malloc(sizeof(str));
  link t;

  while (a[i++] != '\0')
    n++;
  s->len = n;
  s->head = new(NULL, a[0]);
  t = s->head;
  for (i = 1; i < n; i++)
    {
      t->next = new(NULL, a[i]);
      t = t->next;
    }
  return s;
}

int str_len(str s)
{
  return s->len;
}

int str_comp(str s1, str s2)
{
  link t1 = s1->head, t2 = s2->head;

  while ((t1 != NULL) && (t2 != NULL))
    {
      if (t1->item > t2->item)
	return 1;
      if (t1->item < t2->item)
	return -1;
      t1 = t1->next;
      t2 = t2->next;
    }
  if ((t1 == NULL) && (t2 == NULL))
    return 0;
  else
    return (s1->len > s2->len) ? 1 : -1;
}

str str_copy(str dest, str source)
{
  link d, s = source->head->next;
  
  str_destroy(dest);
  dest = malloc(sizeof(str));
  dest->len = source->len;
  dest->head = new(NULL, source->head->item);
  d = dest->head;
  while (s != NULL)
    {
      d->next = new(NULL, s->item);
      d = d->next;
      s = s->next;
    }
  return dest;
}

str str_concat(str s1, str s2)
{
  str s = malloc(sizeof(str));
  link t1 = s1->head->next, t2 = s2->head, t;
  
  s->len = s1->len + s2->len;
  s->head = new(NULL, s1->head->item);
  t = s->head;
  while(t1 != NULL)
    {
      t->next = new(NULL, t1->item);
      t = t->next;
      t1 = t1->next;
    }
  while (t2 != NULL)
    {
      t->next = new(NULL, t2->item);
      t = t->next;
      t2 = t2->next;
    }
  return s;
}

void str_print(str s)
{
  link t = s->head;
  
  while (t != NULL)
    {
      printf("%c", t->item);
      t = t->next;
    }
}
