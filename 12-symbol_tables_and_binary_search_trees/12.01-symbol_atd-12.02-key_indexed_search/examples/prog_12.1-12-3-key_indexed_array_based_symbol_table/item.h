#ifndef ITEM_H
#define ITEM_H

#define maxKey 1000

typedef int Item;
typedef int Key;

Key ITEMrand(int);
Item ITEMscan(Item *);
void ITEMshow(Item);
Key key(Item);

#endif
