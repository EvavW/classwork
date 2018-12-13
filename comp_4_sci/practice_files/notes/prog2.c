#include <stdio.h>
int
main()
{
	int n1, n2, n3;
	double d;
	char c;
	
	printf("Enter a double: ");
	scanf("%le", &d); /* &: address of operator */
	c = 'X';
	
	n1 = 10;
	n2 = 13;
  
	n3 = n1 + n2;
	printf ("n3 = %d d = %le c = %c\n", n3, d, c);

	d = d/3; /* lets do some arithmatic */
	
	printf("now d = %le\n", d);
	return 0;
}
