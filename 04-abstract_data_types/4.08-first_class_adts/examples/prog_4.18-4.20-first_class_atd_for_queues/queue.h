#include "item.h"

typedef struct queue *Q;

void QUEUEdump(Q);
Q QUEUEinit(int);
int QUEUEempty(Q);
void QUEUEput(Q, Item);
Item QUEUEget(Q);
