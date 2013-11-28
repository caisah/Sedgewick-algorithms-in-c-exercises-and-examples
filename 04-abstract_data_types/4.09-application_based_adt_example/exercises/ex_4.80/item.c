#include <stdio.h> 
#include "item.h"

Item item_add(Item a, Item b)
{
  return a+b;
}

Item item_mul(Item a, Item b)
{
  return a*b;  
}

Item item_sub(Item a, Item b)
{
  return a-b;
}

Item item_div(Item a, Item b)
{
  float res = a/b;

  return (int) res;
}

void item_print(Item a)
{
  printf("%d", a);
}
