#include <stdio.h>
#include <math.h>

float raj(float x){

	float y;

	y = (cosf(x)+2)/3;

	return y;

}

int main(){

	float a[100],b[100],c=100.0;
	int i = 1,j = 0;
	b[0] = (cosf(0)-3*0+1);
	printf("\n Enter the initial guess:\n");
	scanf("%f",&a[0]);
	printf("\n\n The values of iterations are:\n\n ");
	while(c>0.00001){
		a[j+1] = raj(a[j]);
		c = a[j+1] - a[j];
		c = fabs(c);
		printf("%d\t%f\n",j,a[j]);
		j++;
	}
	printf("\n The root of the given function is %f\n\n",a[j]);
	printf("Error is: %lf\n",c);

}
