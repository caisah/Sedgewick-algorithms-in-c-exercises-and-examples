#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define M 1000

int main(void) 
{
  int i=-1, count=0, a[MAX], map[MAX], n, j;

  printf("Enter the array: ");
  while (!(feof(stdin)))
    scanf("%d ", &a[++i]);
  n = i;
  for (i = 0; i < n; i++)
    map[i] = 0;
  for (i = 0; i < n-1; i++)
    if (a[i] < M && map[i] == 0)
      for (j = i+1; j < n; j++)
	if (a[i] == a[j])
	  {
	    map[j] = 1;
	    map[i] = 1;
	  }
  for (i = 0; i < n; i++)
    if (map[i] == 0)
      count++;

  printf("\nNumber of unique integers: %d\n", count);
  return 0;
}
