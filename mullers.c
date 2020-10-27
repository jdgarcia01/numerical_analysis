#include <stdio.h>
#include <math.h>

double func(double x){

	return (16 * x * x * x *x - 40 * x *x * x + 5 * x * x + 20 * x + 6);
}

int main(){

	int N0 = 20;
	//printf("Number of iterations: \n");
	//scanf("%d\n",&N0);

	double p;
	double p0 = 0.5;

	double p1 = -0.5; 
	double p2 = 0; 

	double TOL = pow(10,-5);
	printf("Tolerance is: %lf\n", TOL);

	double h1 = p1 - p0;
	double h2 = p2 - p1;
	double h;

	double delta1 = (func(p1) - func(p2))/h1;
        double delta2 = (func(p2) - func(p2))/h2;
	double d = (delta2 - delta1)/(h2 - h1);
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
		
		if( fabs(h) < TOL){
			printf("OUTPUT: %lf\n", p);
			break;
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
