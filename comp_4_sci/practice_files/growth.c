/*example of how to write to an output file as well as for a differential growth equation
fprintf(FILE*,"____", _, _, _, _);
FILE *fp;
fp = fopen("growth.txt", "w"); w= write r= read a = append

HOW TO IMPROVE:

Runga-Kutta Method:

uses more derivitate information to step forwad by 1/2deltat - then calcs slope at the point then goes back to the beginning of the integral and uses that slope to extrapolate forward
uses deriviateinfor at the beginning and at the midpoint of the integral

dx/td = F([x,t]
xi+1/2 = xi + deltat/2 + F[x;,t;]
xi+1 = xi+deltat F[xi+1/2,ti+1/2]

how to solve two equations while integrating them together in time 

R = population of rabbits
F = population of foxes

Malthusian Growth:
dN/dt = rN

dR/dt=rr R(1-F/fc) **rsubscript R = growthrate
	if F>Fc than dR/dt <0
	if F<Fc than dR/dt >0

dF/dt = rf F(R/Rc -1) **r subscript F = grwothrate

NON-DIMENSIONALIZE:

r = R/Rc **not the same r as in growth rate 
f = R/Rc
tau = rr*t 
roe = rf/rr

dr/dt = rr*r(1-f)
df/dt = rf(r-1)

dr/dtau = r(1-f)
df/dtau = roepf(r-1)

Euler method review: 
dx/dt = F[x,t]
x(t+deltat) - x(t)/ deltat =ish F[x,t]

x(t+deltat) = x(t) + delatat F[x(t),t]
xi+1 - xi + deltat * F[xi,ti]

Rabbits and Foxes:
Euler Equations:
ri+1 = ri + deltat ri(1-fi)
fi+1 = fi + deltat fi(ri-1)

f[t-0] = f0
r[t=0] = r0

double rip1, ri, fip1, fi, t, dt;
double rho = 2.0;
int n (number of time steps), i;
FILE *fp;
printf("Enter r0 and f0:");
scanf("%le%le", &ri, &fi);
printf("Enter tmax and N:");
scanf("%le%d", &tmax, &n);
dt - tmax/n;
fp = fopen("rf_growth.txt", "w");
fprintf(fp,"%le%le%le\n", 0.0, ri, fi);

for (i = 0; i<n; i++){
ripi = ri + dt * ri * (1-fi);
fipi = fi + dt * rho * fi * (ri - 1);
t = (i + 1) * dt;
fprintf(fp, "%le %le %le\n",t,rip1, fip1);
ri = rip1
fi = fip1
}




 */

#include <stdio.h>
#include <math.h>

int 
main()
{
	double t, n, dt, tmax, r, n0, nexact, n12, nc = 2.0; //r = timestep? n12 = ????
	int i, m; //m=number of discrezation points
	FILE *fp; //initialize file opener

	fp = fopen("growth.txt", "w"); //open and create file called growth.txt
	
	printf("Enter tmax, n0, r, m: ");
	scanf("%le %le %le %d", &tmax, &n0, &r, &m);

	t = 0.0; //time equal to 0
	dt = tmax/m; // differential time step
	n = n0; //initial n to n0

	fprintf(fp, "%le %le %le %le\n", t, n, n0, 0.0);

	for( i = 0; i < m; i++){
		// n += dt * r *n; // old Euler method
			
		n12 = n + dt/2 *r *n;
		
		n += dt * r *n12; //Runga-Kutta Method 	
		t += dt;

		nexact = n0*exp(r*t);

		fprintf(fp, "%le %le %le %le\n", t, n, nexact, 100*(n-nexact)/nexact);
	}
	fclose(fp);
	return 0;
}
	 
