#include <stdio.h> 
#include <stdlib.h> 
#include "item.h"
#include "st.h"

Key ITEMrand(int maxN)
{
  return (rand() % maxN);
}  

Item ITEMscan(Item* x)
{
  return scanf("%d", x);
}

void ITEMshow(Item x)
{
  printf("%d ", x);
}

Key key(Item item)
{
  return (item);
}
