#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define M 4
#define N 15

void distcount(int a[], int l, int r)
{
  int i, j, cnt[M], b[N];

  for (j = 0; j < M; j++)
    cnt[j] = 0;
  for (i = l; i <=r; i++)
    cnt[a[i]+1]++;
  for (j = 1; j < M; j++)
    cnt[j] += cnt[j-1];
  for (i = l; i <= r; i++)
    b[cnt[a[i]]++] = a[i];
  for (i = l; i <= r; i++)
    a[i] = b[i-l];
}

void print_array(int a[], int n)
{
  int i;
  
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}  

int main(void) 
{
  int i, j, a[N];

  srand(time(NULL));
  for (i = 0; i < N; i++)
    a[i] = rand() % M;
  printf("Initial: \n");
  print_array(a, N);
  distcount(a, 0, N);
  printf("Final: \n");
  print_array(a, N);
  
  return 0;
}
