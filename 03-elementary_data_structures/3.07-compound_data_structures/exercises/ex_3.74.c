#include <stdio.h>
#include <stdlib.h>

int vertices(int **adj, int n)
{
  int a, b, c, s = 0;

  for (a = 0; a < n; a++)
    for (b = 0; b < n; b++)
      if (!(adj[a][b]))
	for (c = 0; c < n; c++)
	  if (adj[a][c] && adj[c][b])
	    s++;
  return s/2;
}

int main(int argc, char *argv[])
{
  int i, j, **adj, v = atoi(argv[1]);

  adj = malloc(v * sizeof(int*));
  for (i = 0; i < v; i++)
    adj[i] = malloc(v * sizeof(int));
  for (i = 0; i < v; i++)
    for (j = 0; j < v; j++)
      adj[i][j] = 0;
  for (i = 0; i < v; i++)
    adj[i][i] = 1;
  printf("Enter the edges(press letter to exit): ");
  while (scanf("%d %d\n", &i, &j) == 2)
    {
      adj[i][j] = 1;
      adj[j][i] = 1;
    }
  for (i = 0; i < v; i++)
    {
      for (j = 0; j < v; j++)
  	printf("%d ", adj[i][j]);
      printf("\n");
    }
  printf("Number of vertices: %d\n", vertices(adj, v));
  return 0;
}
