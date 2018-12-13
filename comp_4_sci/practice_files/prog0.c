/* 
Program Assignment 0
Computing for Scientists
Eva von Weltin 
9/30/2016


Program calcs snd prints sin cos tan for -180 to +180 degree
*/

#include <stdio.h>
#include <math.h> /* import math library*/

int 
main()
{
	//initialize variables
	int degree;
	double angleMeasureRadians;
	double sinAngle;
	double cosAngle;
	double tanAngle;

	// print data labels
	printf("\n");
	printf(  "Degree     Radians         sin             cos           tan\n");

	for (degree = -180; degree < 180; degree = degree + 1) {
		angleMeasureRadians = ( degree * M_PI) / 180;
		sinAngle = sin(angleMeasureRadians);
		cosAngle = cos(angleMeasureRadians);
		tanAngle = tan(angleMeasureRadians);
		printf("%d  %le  %le  %le  %le", degree, angleMeasureRadians, sinAngle, cosAngle, tanAngle );
		printf("\n");
		}
	return 0;
}		


/* how to compile: cc prog0.c -o prog0 -lm */
