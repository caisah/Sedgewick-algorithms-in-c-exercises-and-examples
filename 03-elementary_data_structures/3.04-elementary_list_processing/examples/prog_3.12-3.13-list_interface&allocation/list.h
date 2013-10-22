typedef struct node* link;
typedef int itemType;
struct node
{
  itemType item;
  link next;
};
typedef link Node;
void initNodes(int);
link newNode(int);
void freeNode(link);
void insertNext(link, link);
link deleteNext(link);
link Next(link);
int Item(link);
