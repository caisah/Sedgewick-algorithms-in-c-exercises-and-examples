#include <stdio.h> 
#include <stdlib.h> 
#include "item.h"

Key ITEMrandkey()
{
  return (rand() % maxKey);
}  

Item ITEMrand(Key key)
{
  Item item = malloc(sizeof(Item));
  
  key(item) = key;
  item->value = (rand() % maxN);
  return item;
}

void ITEMshow(Item item)
{
  printf("key: %d, value: %d\n", item->keyVal, item->value);
}

