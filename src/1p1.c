#include <stdio.h>
#include <stdlib.h>
#include "common/helper.h"

int factorpair(int additive, int n, int *arr)
{
  int a=0, b=1;
  while((arr[a] + arr[b]) != additive)
  {
    b++;
      if (a==b)
      {
          b++;
      }
    if (b == n)
    {
        b = 0;
        a++;
    }
    if(a==n)
    {
        printf("oops!\n");
        break;
    }
  }
  return(arr[a]*arr[b]);
}

int main(int argc, char** argv)
{
  int element, i, n;
  int *arr;

  if(argc != 2)
  {
      printf("usage: %s input_file\n", argv[0]);
      return -1;
  }

  // Populate array
  arr = arrayNumbersFromFile(argv[1], &n);
  if (n < 1)
  {
      fprintf(stderr, "No array populated, exiting!\n");
  }

  // Get the Multiplicitive result from factors that add to 2020
   element = factorpair(2020, n, arr);
   printf("%d\n", element);

  // Free the array
  free(arr);

  return 0;
}


