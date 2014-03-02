#ifndef PQINDEX_H
#define PQINDEX_H

int less(int, int);
void PQinit(void);
int PQempty();
void PQinsert(int);
int PQdelmax();
void PQchange(int);
void PQdelete(int);

#endif
