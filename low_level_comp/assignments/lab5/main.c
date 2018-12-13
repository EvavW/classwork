#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int poly(int x, int a, int b, int c);

int between(int x, int a, int b);

void dblit(int *arr, int length);

int main(){

  int poly_val = poly(2,1,2,3);
  printf("poly_val: %d\n", poly_val);

  int between_val = between(3,2,4);
  printf("between_val: %d\n", between_val);

  int *arr = (int*)malloc(sizeof(int)*4);
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 3;
  dblit(arr,4);

  free(arr);
  return 0;
}
