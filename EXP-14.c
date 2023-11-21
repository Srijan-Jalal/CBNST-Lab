#include<stdio.h>
double DIFF_func(double x,double y)
{
	return (y-x)/(y+x);
}

int main(void)
{
	int n;
	double h;
	printf("Enter The No of Intervals: ");
	scanf("%d",&n);
	double X[n+1],Y[n+1];
	printf("Enter The Intial X: ");
	scanf("%lf",&X[0]);
	printf("Enter The Intial Y: ");
	scanf("%lf",&Y[0]);
	printf("Enter The Value of X which need to be Guessed: ");
	scanf("%lf",&X[n]);
	h = (X[n]-X[0])/n;
	for(int i=1;i<n+1;i++)
	{
		X[i]=X[i-1]+h;
		Y[i]=Y[i-1]+h*(DIFF_func(X[i-1],Y[i-1]));
	}
	for(int i=0;i<n+1;i++)
	{
		printf("%lf \t\t %lf \n",X[i],Y[i]);
	}
	printf("Value of Y at X=%lf is: %lf",X[n],Y[n]);
	return 0;
}