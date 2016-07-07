#include <stdlib.h>

int main()
{
  /* allocating space for 4 integers */
  int *arr = malloc(4*sizeof(*arr));
  int i;
  /* notice we'll write one past the bounds of the array */
  for (i = 0; i<5; i++)
    {
      arr[i] = i;
    }
  /* should be freeing here */
  return 0;
}
