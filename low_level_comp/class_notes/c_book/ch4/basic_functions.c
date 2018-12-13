#include<stdio.h>
#include<stdlib.h>

#define PI  3.14159

void func();
double area(double radius);

int main() {

  func(); // call func
 
  double radius = 2;
  printf("the area is: %1.3f\n", area(radius));

  return 0;

  
}

void func() {

  printf("in func\n");

  return; // don't need this in void functions, but should include.
}

double area(double radius) {

  return PI * radius * radius;

}
