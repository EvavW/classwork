/* md^2x/dt^2 = -kx-gammax/dt + F0sin(omega0t)
d^2x/dt^2 = -omega^2x-(gamma/M)(dx/dt) + F/M sin(omega0t)
omega = radical(k/M)




d^2X/dtau^2 = -x - (gamma/omegaM)(dx/dtau)+ (f0/omega^2M)sin(


??????


//Assignment 2 poplation biology

two population 
growth terms 	NR = rabbits
		NF = foxes
growth rates
		rF
		rF
initial population densities
		NR,0
		NF,0
critical population densities
		NR,C
		NF,C
if NF>NFc the gwoth rate of the rabbit pop becomes negative because too many are being eaten 
if NR<NR,C thefoxes' growth rate becomes negateive becuase they will starve becuase there are not enough rabbits

N = 2
y1 = NR
y2 = NF
F1[NR,NF,t] = rFNR(1-NF/NF,C)
F2[NR,NF,t] = rFNF(NR/NR,C -1)
y1,0 = NR,0
y2,0 = NF,0
all dependent values will be put in an array of length N and we'll use one function call to advance y(t)towardsy(t+deltat)
Nc =  critical density 

dN/dt = rN
N(t) = N0e^rt
How can we improve this to make it more realistic?

Logsitic Equation:

dN/dt = rN(1-N/Nc)
if N>Nc than dN/dt <0
if N<Nc than dN/dt > 0

on a graph with t on x axis and Nc on y axis:
if N>Nc population will approach Nc aseptopeably from below 
if N<Nc population will approach Nc asemtopably from above 
*/

#include <stdio.h>
#include <math.h>

int main()
{
	double t, n, dt, tmax, r





