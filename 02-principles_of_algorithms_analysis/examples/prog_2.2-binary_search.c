#include <stdio.h>

int search(int[], int, int, int);

int main(void) 
{
  int i=-1, n, v;
  int a[100];

  printf("Enter the array: ");
  while (!feof(stdin))
    scanf("%d ", &a[++i]);
  n = i+1;
  printf("\nEnter the number to search: ");
  scanf("%d", &v);
  printf("%d\n", search(a, v, 1, n));
  return 0;
}

int search (int a[], int v, int l, int r)
{
  while (r >= 1)
    {
      int m = (l+r)/2;
      if (v == a[m])
	return m;
      if (v < a[m])
	r = m - 1;
      else
	l = m + 1;
    }
  return -1;
}
