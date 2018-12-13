/*Rabbits and Foxes:
Euler Equations:
ri+1 = ri + deltat ri(1-fi)
fi+1 = fi + deltat fi(ri-1)

f[t-0] = f0
r[t=0] = r0

Runga-Kutta Method:
take a half step Euler Method and then use that info to take a full step 

dr/dt = r(1-f) = P(r,f)
df/dt = rhof(r-1) = Q(r.f)

r1+1/2 = ri + delta/2 * P(ri,fi)
f1+1/2 = fi + deltat/2 * G(ri,fi)

ri+1 = ri + deltat + P(ri+1/2,f1+1/2
fi+1 = fi + deltat * Q(ri+1/2 , fi+1/2)
*/

#include <stdio.h>
#include <math.h>


int main() 
{
	// initiate variables
	double ri, rip1; // r = R/Rc  = rabbit population/ rabbit critical population
	double fi, fip1; // f = R/Rc = fox population/ fox critical population
	double ri12, fi12; // half Euler step 
	double t = 0.0;
	double dt, tmax; //  time derivative, max time
	double rho; // rho = fr/rr =rabbit growth rate/fox starvation rate
	
	int n, i; //n= number of time steps, i = for loop counter 
	FILE *fp; //for file printing

	// get user input
	printf("Enter r0 and f0:"); // initial values for r and f
	scanf("%le %le", &ri, &fi); // pass initial values to ri and fi
	printf("Enter tmax, n, and rho:");
	scanf("%le %d %le ", &tmax, &n, &rho);
	
	// print to file 
	fp = fopen("rf_growth.txt", "w"); //open file for writing
	fprintf(fp,"%le %le %le\n", t, ri, fi); 
	
	// print to console: REMOVE LATER
	printf("%le %le %le\n", 0.0, ri, fi);
	
	// set dt
	dt =  tmax / n; 
	
	// 
	for (i = 0; i<n; i++){
		//Euler Method 
			//rip1 = ri + dt * ri * (1-fi);
			//fip1 = fi + dt * rho * fi * (ri - 1);
			//t = (i + 1) * dt;

		//Runga-Kutta Method
		// half of a Euler Step
		ri12 = ri + ( dt/2) * ri * (1-fi);
		fi12 = fi + ( dt/2) * rho * fi * (ri -1);
		// full Euler step using r and f from half step
		rip1 = ri + dt * ri12 * (1 - fi12); 
		fip1 = fi + dt * rho * fi12 * (ri12 - 1);
		// update time
		t = (i + 1) * dt;
		
		// print to file
		fprintf(fp, "%le %le %le\n", t, rip1, fip1);
		
		//print to console: REMOVE LATER
		printf("%le %le %le\n", t, rip1, fip1);		

		// update ri and fi for next iteration ( no longer r0 and f0 )
		ri = rip1;
		fi = fip1;
	}
	
	return 0;
	}
