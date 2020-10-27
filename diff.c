#include <stdio.h>
#include <math.h>

double func(double x){

	return x * x;
}

int main(){

	double x0 = 2;
	double xn = 4;
	double h = 0.5;

	double delta_x = (xn - x0)/h;
	int a = 0;
	int b = 1;
	int iter = 20;
	int i = 1;
	double p = 0;
	double p0 = .02;
	double x = 0.0001;

	while( i <= iter){

		p = (func(p0 + delta_x) - func(p0))/delta_x;	
		printf("%lf\n",p);
		p0 = p;

		i++;

	}


	return 0;

}
