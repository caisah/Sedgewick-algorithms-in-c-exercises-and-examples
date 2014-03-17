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

Key ITEMrandkey(void);
Item ITEMrand(Key);
void ITEMshow(Item);
Key key(Item);

#endif
