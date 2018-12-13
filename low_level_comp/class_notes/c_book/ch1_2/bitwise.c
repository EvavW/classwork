#include <stdio.h>
#include <stdlib.h>

int main () {

  // move bits by position 
  
  unsigned char d = 1; // d =1
  printf("d = %d\n", d);

  d =d <<3; // d = 8
  printf("d = %d\n", d);

  unsigned char c = 129; // c =129
  printf("c = %d\n", c);

  c =c <<1; // c = 2
  printf("c = %d\n", c);

  c = 129;
  c <<= 1; // c= 2
  printf("c = %d\n", c); 
  c = 129;
  c ^= 1; // c = 128
  printf("c = %d\n", c);  


  printf("null = %d EOF = %d\n", '\0', EOF); // ??? 

  /*

    & and
    | or
    ^ exclusive or
  */

  
}
