#include <stdio.h>
#include <math.h>

double derive(double (*f)(double), double x0){

	const double delta = 1.0e-6;
	double x1 = x0 - delta;
	double x2 = x0 + delta;
	double y1 = f(x1);
	double y2 = f(x2);

	return (y2 - y1)/(x2 - x1);

}


int main(){


	const double delta = 1.0e-6;
	const double delta2 = pow(10,-6);

	printf("value is: %lf\n",delta);
	printf("value is: %lf\n",delta2);

	double der = derive(sin,0.0);
	printf("%lf", der);

	return 0;
}
