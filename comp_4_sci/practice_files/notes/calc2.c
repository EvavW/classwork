/*  */

#include <stdio.h>

int

main()
{
	double n1, n2, res;
	char op;
	
	printf("\nEnter expression in form \"number [+|-|*|/] number\": ");  /* \" makes sure program doesnt interpert " as the end of the string*/

	scanf("%le %c %le", &n1, &op, &n2); 

 	if (scanf("%le %c %le", &n1, &op, &n2) != 3) {
		printf(" *** error: input must be \"number  [+|-|*|/] number\"\n");
		flush(stdin);
		continue; 
		}	
	if (op == '+')
		res = n1 + n2;
	else if (op == '-')
		res = n1 - n2;
	else if (op == '*')
		res = n1 * n2;
	else if  ( op == '/')
		res = n1 / n2;
	else {
		printf(" *** error %c is an invalid operator.\n", op);
		return 2;
	}
	
	printf("%lf %c %lf = %lf\n", n1, op, n2, res);

	}
}
void
flush(FILE *stream)
{
	int c;

	while((c=fgetc(stream)) != EOF 
