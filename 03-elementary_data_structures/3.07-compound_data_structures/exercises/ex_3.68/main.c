#include <stdio.h>
#include <stdlib.h>
#include "link.h"

int main(void)
{
  int n;
  link **m1, **m2, **m3;

  printf("Enter the size of the matrixes: ");
  scanf("%d", &n);
  printf("Enter values for 1st matrix: \n");
  m1 = read_multi(n);
  printf("Enter values for 2nd matrix: \n");
  m2 = read_multi(n);
  print_matrix(m1, n);
  print_matrix(m2, n);
  m3 = multiply_matrices(m1, m2, n);
  print_matrix(m3, n);
  return 0;
}
