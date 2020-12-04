#include <stdio.h>
#include <stdlib.h>
#include "common/helper.h"

int factorTriplet(int additive, int n, int *arr)
{
  int a=0, b=1, c=2;
  while((arr[a] + arr[b] + arr[c]) != additive)
  {
    c++;
    if (c==b || c==a)
    {
        c++;
    }
    if (c==n)
    {
        c = 0;
        b++;
    }
    if (b==a || b==c)
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
  return arr[a] * arr[b] * arr[c];
}

int main(int argc, char** argv)
{
  int element, i, n=0;
  int *arr;
  if(argc != 2)
  {
  fprintf(stderr, "usage: %s input_file\n", argv[0]);
      return -1;
  }

  arr = arrayNumbersFromFile(argv[1], &n);

  if (arr == NULL)
  {
      return -3;
  }

  element = factorTriplet(2020, n, arr);
  printf("%d \n", element);
  free(arr);
  return 0;
}


