/* 

Computing for Scientists: Programming Assignment 1

Eva von Weltin 
10/11/16

Program calculates intergral of cos(x^2) based on inputed upper and lower limits of integration. 
Integral calculated using Trapezoid Rule 

*/
# include <stdio.h>
# include <math.h>

int
main()
{
	//decalre variables 
	double a, b, x, result, dx; // upper and lower limits of integation, accumulator, mulitplier
	double n; //non-rounded value of n
	int nr; // rounded value of n  
	int i; // counter variable 
	double f(double); // function whose name is f that takes a double and returns a double 
	
	printf("Enter a and b: ");
	scanf("%le %le", &a, &b); 

	n =((100*b)/(2*M_PI))*(b-a)+1; //equation to automatically calculate optimal n 
	nr = round(n); // rounded  n 

	dx = (b-a)/(nr-1); // to calc delta x take the entrire integral a-b and subtracting from the entrire number of trapezoids n 
	result = 0; // initalize accumulator variable at 0

	for ( i= 0; i<n; i++) { 
				
		x = a + i*dx;
		
		if (i ==0 || i == n-1) // || means or 
			result += f(x); //+= means add into

		else 
			result += 2*f(x);

		}
	
	
	result  *= dx/2; // multiples result by dx/2 nd then return the result to result

	printf("Calculated n = %d\n", nr);
	
	printf("Integral from %le to %le = %le\n", a, b, result); // print result
	
	return 0; 
}

// define f(x)

double 
f(double x)
{
	return cos(x*x);
}
