#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func(double x){


	return (x*x*x + 4 * x * x - 10);

}

int main(){

	double p0 = 0.5;
	double p = 0;
	float TOL = 0.001;
	int N0 = 10;
	int i = 0;

	while(i <= N0){
	
		p = func(p0); 
		printf("%lf\n",p);
		if( fabs((p - p0)) < TOL){
			printf("fixed point is: %lf\n",p);
			break;
		}
		i += 1;
		p0 = p;
		if( i == N0){
			printf("Method failed after %d\n", N0);
			exit(0);
		}
		

	}

		

}
