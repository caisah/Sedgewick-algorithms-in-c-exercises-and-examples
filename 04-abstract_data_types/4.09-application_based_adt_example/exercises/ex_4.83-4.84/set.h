#ifndef SET_H
#define SET_H

typedef struct Set *set;

set set_init(int);
void set_add(set, int);
set set_union(set, set);
set set_intersection(set, set);
set set_complement(set);
void set_print(set);

#endif
