/* arrays 

 char  c [10];  // char makes it an array of cahracters
		// int would make it an array of integers (more than just 1 byte per item)
 	says that there is an array called c that has a maximum of 10 bytes


for (i=0; i<10, i = i + 1)
	c[i] = 'A';
	
c[5] = 'B';
 
for (i=0; i<10, i = i + 1);
	printf("%c ", c[i]);
 			deferences the c array?
logic:
c[i] == *( c + i )
		* is the "contents of" operator 

c[0] == c
c[5] == 5 byte within the array? 

*/


# include <stdio.h>
int
main()
{
 	char c[10];

	int i;
	void printit(char *, int);

	printf("%u %u\n", c, &c[0]);

	for (i = 0; i<10; i =i+1){
		c[i] = 'A';
		printf("%c ",c[i]);
	}	

	printf("\n");	

	c[5] = 'B';
	
	for (i = 0; i<10; i =i+1){
		printf("%c ",c[i]);	
	}
	printf("\n");

	printit(c, 10); 
	
	return 0;
}

void
printit(char  *x. int n);
//  /* *n means the contents of x */
{
	int i;

	for (i=0; i < n; i = i+1) {
		printf("%c ", x[i]);
	}
	printf("\n");

 	return; 
}
