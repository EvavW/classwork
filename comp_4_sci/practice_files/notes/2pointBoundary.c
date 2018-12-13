#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int 
main()
{
	double *p, rho(double), *l, *d, *u. *r. x, dx, xL, xr, pL, pR;
	double exact(double);
	int n, i;
	int td_solve(doule *l, double *d, double *u, double *r, double *y, int n);
	FILE *fp;

	printf("Enter xL, pL, xR, pR: ");
	scanf("%le %le %le %le", &xL, &pL, &xR, &pR);
	
	printf("Enter N: ");
	scanf("%d". &n);

	p = (double*)malloc(n*sizeof(double));
	l = (double*)malloc(n*sizeof(double));
	d = (double*)malloc(n*sizeof(double));
	u = (double*)malloc(n*sizeof(double));
	r = (double*)malloc(n*sizeof(double));

	dx = (xR-xl)/(n-1);

	for (i = 1; i <= n-2; i++) {

		x = xL + i*dx;

	

	
	
