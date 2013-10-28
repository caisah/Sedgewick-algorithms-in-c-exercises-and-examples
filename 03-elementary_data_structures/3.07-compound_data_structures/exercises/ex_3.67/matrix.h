typedef struct node link;
struct node
{
  int val;
  link *next;
};

int **malloc2d(int, int);
link *new(int, link*);
void print_list(link*);
