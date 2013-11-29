#include <stdio.h> 
#include "str.h"

int main(void) 
{
  str s1, s2, s3, s4;

  s1 = str_create("abc");
  s2 = str_create("abe");
  s3 = str_create("aaa");
  printf("Comparison between: ");
  str_print(s1);
p  printf(" ");
  str_print(s2);
  printf(" %d\n", str_comp(s1, s2));
  str_copy(s1, s2);
  str_print(s1);
  s4 = str_concat(s1, s2);
  str_print(s4);
  printf("\n");
  return 0;
}
