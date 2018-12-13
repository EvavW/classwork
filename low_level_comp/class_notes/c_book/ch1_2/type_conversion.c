#include <stdio.h>
#include <stdlib.h>

int main() {

  // type conversions

  double d = 4.5;
  int i = (int)d; // convert from double to int. removes everything after the decimal point. i = 4

  double d1 = d -i ; // this will work. i will be cast to a double for the calcualtion. will return a double.

  printf("d = %f i = %d d1 = %f\n", d, i, d1);

  char str[] = "123";

  int j = atoi(str); // convert from string to int
  // atof covnerts from atoi to atof

  printf("str = %s j = %d\n", str, j); 

  return 0;

  /*
(char can be converted to short can be converted to int...)
char
short
int
longlong
long
float
double
  */










}
