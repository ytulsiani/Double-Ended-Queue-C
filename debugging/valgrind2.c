#include <stdlib.h>

typedef struct _bstnode{
  int data;
  struct _bstnode *left;
  struct _bstnode *right;
} BSTNode;

int main()
{
  BSTNode *my_node = malloc(sizeof(*my_node));
  if (my_node->data == 5)
    {
      //do something awesome
    }
  else
    {
      //do something less awesome
    }
  free(my_node);
}
