#ifndef PQFULL_H
#define PQFULL_H

#include "item.h"

typedef struct pq* PQ;
typedef struct PQnode* PQlink;

PQ PQinit(void);
int PQempty(PQ);
PQlink PQinsert(PQ, Item);
Item PQdelmax(PQ);
void PQchange(PQ, PQlink, Item);
void PQdelete(PQ, PQlink);
void PQjoin(PQ, PQ);

#endif
