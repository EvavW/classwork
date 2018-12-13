#include<stdio.h>

int main() {

  /* declearing an array of characters */

  char string[50];
  string[0] = 'H';
  string[0] = 'e';
  string[0] = 'l';
  string[0] = 'l';
  string[0] = 'o';
  string[0] = '/n';

  printf("%s\n", string);
  printf(" Enter your name: ");
  scanf("%s" , string);
  printf("Hello %s\n", string);

  char string2[] = "Hello";



}
