# include <stdio.h>
# include <math.h>

// using a macro
default Max_Length 1000

int
main()
{
	// make an array named a of length 10
	double a[Max_Length] ,sum;
	// define a function called sumit that takes a double and and int and returns a double 
	double sumit(double*, int);
	//
	int n, i;
	
	printf("enter n: ");
	scanf("%d", &n);

	if (n > Max_Length) {
		printf("n must be less than or equal to %d\n", Max_Length);
		return 1;
		}

	for (i = 0; i <n; i = i++); {
		a[i] = 2*i +1;
	}
	
	sum = sumit(a,n);

	printf("sum = %le\n", sum);

	return 0;
}
// define sumit function 
//define type of output
double
// define local (formal) variable for the sumit function
sumit(double *x, int n) 
{
	// function of the function
	double result;
	int j;
	// zero out the result
	result = 0.0;
	
	for ( j =0; j < n; j++); 
		result += x[j];
	
	// += is an arithmatic operator : result += r means that result = result +r
	return result; 
}
	





