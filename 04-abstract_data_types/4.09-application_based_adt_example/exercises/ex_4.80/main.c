#include <stdio.h>
#include "item.h"
#include "mat.h"

int main(void) 
{
  Item x = 5, y = 2, x2 = 6, y2 = 3;
  mat m1, m2, k1, k2;
  int i, j;

  printf("\nItems: ");
  item_print(x);
  printf(" ");
  item_print(y);
  printf("\n");
  printf("Item Addition: ");
  item_print(item_add(x, y));
  printf("\n");
  printf("Item Multiplication: ");
  item_print(item_mul(x, y));
  printf("\n");
  printf("Item Substraction: ");
  item_print(item_sub(x, y));
  printf("\n");
  printf("Item Division: ");
  item_print(item_div(x, y));
  printf("\n\n");
  m1 = mat_create(3, 2);
  m2 = mat_create(2, 3);
  k1 = mat_create(2, 2);
  k2 = mat_create(2, 2);
  for (i = 0; i < mat_rows(m1); i++)
    for (j = 0; j < mat_cols(m1); j++)
      mat_add_elem(m1, i, j, x);
  for (i = 0; i < mat_rows(m2); i++)
    for (j = 0; j < mat_cols(m2); j++)
      mat_add_elem(m2, i, j, y);
  for (i = 0; i < mat_rows(k1); i++)
    for (j = 0; j < mat_cols(k1); j++)
      {
  	mat_add_elem(k1, i, j, x2);
  	mat_add_elem(k2, i, j, y2);
      }
  printf("k1 Matrix: \n");
  mat_print(k1);
  printf("k2 Matrix: \n");
  mat_print(k2);
  printf("Addition: \n");
  mat_print(mat_add(k1, k2));
  printf("Substraction: \n");
  mat_print(mat_sub(k1, k2));
  printf("m1 Matrix: \n");
  mat_print(m1);
  printf("m2 Matrix: \n");
  mat_print(m2);
  printf("Multiplication: \n");
  mat_print(mat_mul(m1, m2));
  return 0;
}
