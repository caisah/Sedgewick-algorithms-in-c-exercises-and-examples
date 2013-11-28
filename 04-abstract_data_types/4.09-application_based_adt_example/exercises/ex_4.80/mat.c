#include <stdio.h> 
#include <stdlib.h>
#include "mat.h"
#include "item.h"

// struct Mat contains the matrix, no. of rows & no. of cols
struct Matrix
{
  Item **item;
  int rows;
  int cols;
};

// creates a blank matrix with a no. rows and cols
mat mat_create(int rows, int cols)
{
  mat m = malloc(sizeof(mat));
  int i;

  m->rows = rows;
  m->cols = cols;
  m->item = malloc(rows*sizeof(Item*));
  for (i = 0; i < rows; i++)
    m->item[i] = malloc(cols*sizeof(Item));
  return m;
}

// returns no. of rows
int mat_rows(mat m)
{
  return m->rows;
}

int mat_cols(mat m)
{
  return m->cols;
}
// puts element "val" in matrix "m" at pos i, j
void mat_add_elem(mat m, int i, int j, int val)
{
  if ((i <= m->rows) && (j <= m->cols))
    m->item[i][j] = val;
  else
    {
      printf("Wrong coordinates: (%d, %d)\n", i, j);
      exit(-1);
    }
}

// adds two matrixes
mat mat_add(mat m1, mat m2)
{
  int i, j;
  mat m;

  if ((m1->rows != m2->rows) || (m1->cols != m2->cols))
    {
      printf("Can't add! Matrix dimesions differ.\n");
      exit(-1);
    }
  m = mat_create(m1->rows, m1->cols);
  for (i = 0; i < m1->rows; i++)
    for (j = 0; j < m1->cols; j++)
      mat_add_elem(m, i, j, item_add(m1->item[i][j], m2->item[i][j]));
  return m;
}

// substracts matrix "m2" from "m1"
mat mat_sub(mat m1, mat m2)
{
  int i, j;
  mat m;

  if ( (m1->rows != m2->rows) || (m1->cols != m2->cols))
    {
      printf("Can't add! Matrix dimesions differ.\n");
      exit(-1);
    }
  m = mat_create(m1->rows, m1->cols);
  for (i = 0; i < m1->rows; i++)
    for (j = 0; j < m1->cols; j++)
      mat_add_elem(m, i, j, item_sub(m1->item[i][j], m2->item[i][j]));
  return m;
}

// help function;
// multiplies elements of a "line" from matrix "m1"
// with a "col" from matrix "m2"; returns an int
int mult(int line, int col, mat m1, mat m2)
{
  int i, n = m1->cols;
  int res = item_mul(m1->item[line][0], m2->item[0][col]);

  for (i = 1; i < n; i++)
    res = item_add(res, item_mul(m1->item[line][i],
				 m2->item[i][col]));
  return res;
}

// multiplies matrix "m1" by "m2"
mat mat_mul(mat m1, mat m2)
{
  int i, j;
  mat m;

  if ( (m1->cols != m2->rows) || (m2->cols != m1->rows))
    {
      printf("Can't multiply! Matrix dimensions don't fit!\n");
      exit(-1);
    }
  m = mat_create(m1->rows, m2->cols);
  for (i = 0; i < m->rows; i++)
    for (j = 0; j < m->cols; j++)
      mat_add_elem(m, i, j, mult(i, j, m1, m2));
  return m;
}

// prints matrix m
void mat_print(mat m)
{
  int i, j;

  for (i = 0; i < m->rows; i++)
    {
      for (j = 0; j < m->cols; j++)
	{
	  item_print(m->item[i][j]);
	  printf(" ");
	}
      printf("\n");
    }
}
