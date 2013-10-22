typedef struct node link;
struct node
{
  int item;
  link *next;
};

link *new_node(int);
link *create_list(int);
void print_list(link*);
