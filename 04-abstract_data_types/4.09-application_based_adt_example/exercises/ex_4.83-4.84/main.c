#include <stdio.h> 
#include "set.h"

int main(void) 
{
  set s1, s2;
  int m = 10;

  s1 = set_init(m);
  set_add(s1, 1);
  set_add(s1, 3);
  set_add(s1, 5);
  s2 = set_init(m + 2);
  set_add(s2, 0);
  set_add(s2, 2);
  set_add(s2, 3);
  set_add(s2, 4);
  set_add(s2, 5);
  set_add(s2, 11);
  set_print(s1);
  printf("\n");
  set_print(s2);
  printf("\nIntersection: ");
  set_print(set_intersection(s1, s2));
  printf("\nUnion: ");
  set_print(set_union(s1, s2));
  printf("\nComplement for s2: ");
  set_print(set_complement(s2));
  printf("\n");  
  return 0;
}
