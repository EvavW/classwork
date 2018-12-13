#include <stdio.h>

#define PI 3.14159 /* define PI variable in pre-processing */
/* const double pi = 3.14159; this is how you would define PI within a method */


double area(double radius); /* prototype must be included at the top */

int main() {

    printf("Hello!\n");

    printf("Radius = %1.2f\n", area(2));  /* print the result of the area method with a '2' as the inputed radius */
/* print a double with at most number before decimal point and at most 2 afterthe decimal point */
    
    return 0; /* should always return in main */

    /* ---------------------------- */
    printf("seiz=%d\n", sizeof(int)); /* the size of operator will return 4 bits for a int, 8 for a double, 8 for a long (long interger), 1 byte for a char  */


}

double area( double radius) {

  return PI * radius * radius; /* better to use radius * radius than radius squared (more efficent) */


}


/* how to complie: 

   gcc intro_c.c -o intro_c.exe

   to run:

   ./intro_c.exe

*/
