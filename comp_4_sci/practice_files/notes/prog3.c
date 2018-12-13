#include <stdio.h>
int
main()
{ 
/* example of a very simple function*/

	double a, b;
	double add (double, double); /* asks for two doubles and returns the sum of the two*/

	printf("enter two doubles: ");
	scanf(" %le %le",  &a, &b);
	
	printf("2*(%le + %le) = %le\n" , a, b, 2*add(a, b));
	
	return  0;
}
/* function defenition*/
/* main doesnt know anything about x and y*/
double
add (double x, double y) /* there is no semi colon beause a function defention is mnot a simple statement*/
{
	double z;

	z = x + y;

	return z;
}
