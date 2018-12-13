#include<stdio.h>
#include<math.h>
#define PI 3.14159

// function prototype
double area(double radius);
double volume(double radius, double height);

int main(int argc, char *argv[]) {

  // define variables
  double radius = 0.0;
  double height = 0.0;

  // get radius
  printf("\nEnter radius: ");
  scanf("%lf", &radius);

  // return area 
  printf("Area of a circle= %lf\n", area(radius)); // use %lf for doubles

  //get height
  printf("\nEnter height: ");
  scanf("%lf", &height);
  printf("Area of a cylinder= %lf\n", volume(radius,height));
  

  
}

double area(double radius){
  return PI * radius *radius;

}

double volume(double radius, double height){
  return area(radius) * height; // call area function within this function

}
