#ifndef ITEM_H
#define ITEM_H

typedef double Item;

#define key(A) (A)
#define less(A, B) (key(A) < key (B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define compexch(A, B) if (less(B, A)) exch (A, B)

Item ITEMrand(void);
Item ITEMscan(Item *);
void ITEMshow(Item);

#endif
