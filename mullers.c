/************************************************************
 * Mullers algorithm from "Numerical Analysis 8th edition"  *
 * Authors: Burden and Faires.                              *
 *                                                          *
 *                                                          *
 ***********************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func(double x){

	return (x * x * x - 2 * x * x - 5);
}

int main(){



	int N0 = 0;
	printf("Number of iterations:");
	scanf("%d",&N0);

	double p;
	double p0;
	printf("p0: ");
	scanf("%lf",&p0);
	
	double p1; 
	printf("p1: ");
	scanf("%lf",&p1);

	double p2; 
	printf("p2: ");
	scanf("%lf",&p2);

	// Set the error threshold.
	double TOL = pow(10,-5);
	printf("Tolerance is: %lf\n", TOL);

	double h1 = p1 - p0;
	double h2 = p2 - p1;
	double h = 0;

	double delta1 = (func(p1) - func(p0))/h1;
        double delta2 = (func(p2) - func(p1))/h2;
	double d = (delta2 - delta1)/(h2 + h1);
	int i = 3;
	double b;
	double D;
	double E;

	while(i <= N0){

		b = delta2 + h2 * d;
		D = sqrt((b * b - 4 * func(p2) * d));			

		if( fabs(b - D) < fabs(b + D)){
			E = b + D;	
		} else {
			E = b - D;
		}
		h = (-2 * func(p2)) / E;

		p = p2 + h;

		printf("%lf\n", p );

		if( fabs(h) < TOL){
			printf("OUTPUT: %lf\n", p);
			exit(EXIT_SUCCESS);
		}

		p0 = p1;
		p1 = p2;
		p2 = p;
		h1 = p1 - p0;
		h2 = p2 - p1;
		delta1 = ( func(p1) - func(p0))/h1;
		delta2 = ( func(p2) - func(p1))/h2;
		d = (delta2 - delta1)/(h2 + h1);
		i += 1;	
	}
	printf("Method failed after %d iterations.\n",N0);
	return 0;	




}
