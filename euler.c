#include <stdio.h>
#include <math.h>

// ODE to solve.
double func(double t, double y){

	return(y - t * t + 1 );

}
double exact(double t){

	return( (t + 1)*(t+1) - (0.5) * exp(t));

}

int main(){

	double a,b,N;
	double alpha;

	printf("a endpoint\n");
	scanf("%lf",&a);

	printf("b endpoint\n");
	scanf("%lf",&b);

	printf("intial condition Alpha: \n");
	scanf("%lf",&alpha);

	printf("iterations N:\n");
	scanf("%lf",&N);

	double h;
	printf("h: \n");
	scanf("%lf",&h);

	//double h = (b - a)/N; // Determine step size.
	printf("h is: %lf\n",h);

	double t = a;  
	double w = alpha;
	
	
	for(int i = 1; i <= N; i++){

		w = w + h * func(t,w); // compute wi
		t = a + (i * h);          // compute ti
		printf(" Approximate t is: %lf w is: %lf\t",t , w);
		printf(" Exact value is %lf\t",exact(t));
		printf(" Error is: %lf\n", fabs(exact(t) - w));

	}

	return 0;


}
