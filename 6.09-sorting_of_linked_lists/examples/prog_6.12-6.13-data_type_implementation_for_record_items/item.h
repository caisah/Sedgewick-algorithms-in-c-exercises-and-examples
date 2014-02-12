#ifndef ITEM_H
#define ITEM_H

struct record {
  char name[30];
  int num;
};

typedef struct record *Item;

#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B);

int less(Item, Item);
int ITEMscan(Item *);
void ITEMshow(Item);

#endif
