#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func(double x){

	return (cos(x) - x);
}


int main(){

	double p0 = .5;
	double p1 = 3.142/4 ;
	double TOL = 0.000001;
	double p = 0;
	double q = 0;
	int N0 = 6;

	int i = 2;

	double q0 = func(p0);
	double q1 = func(p1);

	while( i <= N0){
		printf("Iteraration %d\n", i);

		p = p1 - q1 * ((p1 - p0)/(q1 - q0));
		if( fabs(p - p1) < TOL){
			printf("%lf\n",p);
			exit(0);
		} 
		i += 1;
		q = func(p);

		if( q * q1 < 0){
			p0 = p;
			q0 = q1;
		}
		p1 = p;
		q1 = q;
	}
	printf("Failed to find a solution\n");
	return 0;

}
