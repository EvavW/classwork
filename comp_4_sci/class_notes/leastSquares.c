
#include <stdio.h>
#include <math.h>

int
main()
{
        // arrays
        double x[100], y[100], sig[100];
        // accumulators for the running sums
        double s, sx, sxx, sy, sxy, sig2, siga1, siga2;
        double a1, a2, sa1, sa2;
        // file pointer
        FILE *fp;
	FILE *fpp;
        // 
        int n, i;

  	fp = fopen("data.txt", "r");
        
        n = 0;
        
        while(fscanf(fp, "%le %le %le", &x[n], &y[n], &sig[n]) != EOF) n++;
        
	s = 0.0;
	sx = 0.0;
	sxx = 0.0;
	sy = 0.0;
	sxy = 0.0;
	
	for (i = 0; i<n; i++){
	
		sig2 = 1.0/(sig[i]*sig[i]); // 1/ sig^2
		s += sig2; // 1/ sig^2	
		sx += x[i]*sig2; // xi/sig^2
		sxx += x[i]*x[i]*sig2; // xi2/sig^2
		sy += y[i]*sig2; // yi/ sig^2
		sxy += x[i]*y[i]*sig2; // xiyi/sig^2

		}

	a1 = ((sy*sxx)-(sx*sxy))/((s*sxx)-(sx*sx));
	a2 = ((s*sxy)-(sx*sy))/((s*sxx)-(sx*sx));	
		
	siga1 = sqrt((sxx)/((s*sxx)-(sx*sx)));
	siga2 = sqrt((s)/((s*sxx)-(sx*sx)));


	fp = fopen("leastSqr.txt", "w");
	
	for (i = 0; i<n; i++)
		fprintf(fp, "%le %le %le\n", x[i], y[i], (a1 + (a2*x[i]))); 

        return 0;
}       
