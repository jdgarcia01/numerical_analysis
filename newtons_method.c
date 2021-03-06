#include <stdio.h>
#include <stdlib.h>
#include <math.h>



// x^2
double func(double x){

	return (x * x - 6);

}
// 2*x
double func_deriv(double x){

	return(2 * x);

}


int main(){

	double p0 = 1;
	double TOL = 0.01;
	int i = 1;
	int N0 = 100;
	double p;

	while(i <= N0){

		p = p0 - func(p0)/func_deriv(p0);

		if( fabs((p - p0)) < TOL){
			printf("OUPUT: %lf\n",p);
			exit(0);
		}
		if(i == 2)
			printf("p2 is: %lf\n",p);
		i = i + 1;
		p0 = p;

	}



}
