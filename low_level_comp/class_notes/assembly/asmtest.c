#include <stdio.h>

int add64(int a, int b);
void swap64(int *px, int *py);

int main(){

  int sum = add64(1,2);
  printf("sum  = %d\n",sum);

  int x = 10;
  int y = 20;
  printf("x: %d, y: %d\n",  x, y);
  swap64(&x,&y);
  printf("swapped: x: %d, y: %d\n",  x, y);

  return 0;
}

    // gcc -o test asmtest.c add64.s
