#ifndef ITEM_H
#define ITEM_H

#include <string.h>

typedef char *Item;

#define key(A) (A)
#define less(A, B) (strcmp(key(A), key(B)) < 0)
#define exch(A, B) {Item t = A; A = B; B = t;}
#define compexch(A, B) if (less(B, A)) exch (A, B)

int ITEMscan(char **);
void ITEMshow(char *);

#endif
