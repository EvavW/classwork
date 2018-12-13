/*Rabbits and Foxes:
Euler Equations:
ri+1 = ri + deltat ri(1-fi)
fi+1 = fi + deltat fi(ri-1)

f[t-0] = f0
r[t=0] = r0

Runga-Kutta Method:
take a half step Euler Method and then use that info to take a full step 


*/

#include <stdio.h>
#include <math.h>


int main()
{
        // initiate variables
        double ri, rip1; // r = R/Rc  = rabbit population/ rabbit critical population
        double fi, fip1; // f = R/Rc = fox population/ fox critical population
        double ri12; // half Euler step 
        double fi12; // half Euler step
        double t = 0.0;
        double dt, tmax; //  time derivative, max time
        double rho; // rho = fr/rr =rabbit growth rate/fox starvation rate

	double rRunga(double,double);
	double fRunga(double,double,double);

        int n, i; //n= number of time steps, i = for loop counter 
        FILE *fp; //for file printing

        // get user input
        printf("Enter r0: "); // initial value for ri
	scanf("%le", &ri); 
        printf("Enter f0: "); // initial value for fi
	scanf("%le", &fi);
	printf("Enter n: "); // number of discretzation points
	scanf("%d", &n);
	printf("Enter rho: ");
	scanf("%le", &rho);
	printf("Enter tmax: ");
        scanf("%le", &tmax);

        // print to file 
        fp = fopen("PA2.txt", "w"); // open file for writing
        fprintf(fp,"%le %le %le\n", t, ri, fi);

        // set dt
        dt =  tmax / n;

        // 
        for (i = 0; i<n; i++){
                //Runga-Kutta Method
                // half of a Euler Step
                ri12 = ri + rRunga(ri,fi) * (dt/2);
                fi12 = fi + fRunga(ri,fi, rho) * (dt/2);
                // full Euler step using r and f from half step
                rip1 = ri + rRunga(ri12,fi12) * dt;
                fip1 = fi + fRunga(ri12,fi12, rho) * dt;
                // update time
                t = (i + 1) * dt;

                // print to file
                fprintf(fp, "%le %le %le\n", t, rip1, fip1);

                // update ri and fi for next iteration ( no longer r0 and f0 )
                ri = rip1;
                fi = fip1;
        } // close for loop

        return 0;
} // close main

//define functions
double 
rRunga(double r,double f)
{
	return r * (1-f);
}
double
fRunga(double r,double f,double rho)
{
	return rho * f * (r-1);
}








