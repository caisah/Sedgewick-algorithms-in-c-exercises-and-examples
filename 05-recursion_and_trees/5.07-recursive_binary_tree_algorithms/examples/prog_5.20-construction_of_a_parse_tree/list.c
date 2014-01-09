#include <stdio.h> 
#include <stdlib.h>
#include "item.h"
#include "list.h"

int i = 0;

link new(char token, link l, link r)
{
  link x = malloc(sizeof(link));

  x->token = token;
  x->r = r;
  x->l = l;
  return x;
}

link parse()
{
  char t = a[i++];
  link x = new(t, NULL, NULL);

  if ((t == '+') || (t == '*'))
    {
      x->l = parse();
      x->r = parse();
    }
  return x;
}  
