#include <stdio.h>
#include <math.h>

double func(double x)
{
	//return (x*x*x - 7 * x*x + 14 *x - 6);
	return (cos(exp(x) - 2) + 2 - exp(x));
}

double TOL=0.00001;
double p;
double i = 0;
double FA = 0;
int N0 = 1000;
double FP = 0;

void bisection(double a,double b){

	if(func(a) * func(b) >= 0)
	{
		printf("Incorrect a and b");
		return;
	}

	p = a;
	FA = func(a);

	while(i < N0)
	{
		p = a + (b - a)/2;
		FP = func(p);
	
		if(FP == 0 || (b - a)/2 < TOL){
			printf("Root is %lf\n",p);
			break;
		}
		i += 1;

		if(FA * FP > 0){
			a = p;
			FA = FP;
		} else {
			b = p;
		}

	}

}

int main(){

	double a,b;
	a = .5;
	b = 1.5;

	printf("The function used is cos(exp(x) - 2) + 2 - exp(x)\n");
	printf("a = %lf\n",a);
	printf("b = %lf\n",b);
	bisection(a,b);
	printf("\n");
	printf("Accurate root calculated is = %lf\n",p);

	return 0;
}
