#ifndef ITEM_H
#define ITEM_H

typedef int Key;
struct record
{
  Key keyVal;
  int value; //Can change value type
};
typedef struct record *Item;

#define maxN 1000
#define maxKey 100
#define NULLitem NULL
#define key(A) ((A)->keyVal)

Key ITEMrandkey(void);
Item ITEMrand(Key);
void ITEMshow(Item);

#endif
