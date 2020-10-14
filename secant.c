#include <stdio.h>
#include <math.h>
#include <stdlib.h>



double func(double x){

	return (x*x - 6);

}

int main(){

	int i = 2;
	double q0;
	double q1;
	int N0 = 10;
	double p0 = 3;
	double p1 = 2;
	double p;
	double TOL = 1.0e-5;

	printf("TOL is %lf\n",TOL);

	 q0 = func(1);
	 q1 = func(0);
	while(i <= N0){
	 	p = p1 - q1 *(p1 - p0)/(q1 - q0);

		if( fabs(p - p1) < TOL){
			printf("Output is: %lf\n",p);
			exit(0);
		}
		i += 1;
		p0 = p1;
		q0 = q1;
		p1 = p;
		q1 = func(p);

	}
	


}

