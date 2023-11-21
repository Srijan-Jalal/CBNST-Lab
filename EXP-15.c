#include<stdio.h>
double DIFF_func(double x,double y)
{
	return x+(y*y);
}

double find_K(double x,double y,double h)
{
    double k1 = h * (DIFF_func(x,y));
    double k2 = h * (DIFF_func(x+(h/2),y+(k1/2)));
    double k3 = h * (DIFF_func(x+(h/2),y+(k2/2)));
    double k4 = h * (DIFF_func(x+h,y+k3));
    return (k1+2*(k2+k3)+k4)/6;
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
		Y[i]=Y[i-1]+find_K(X[i-1],Y[i-1],h);
	}
	for(int i=0;i<n+1;i++)
	{
		printf("%.4lf \t\t %.4lf \n",X[i],Y[i]);
	}
	printf("Value of Y at X=%.4lf is: %.4lf",X[n],Y[n]);
	return 0;
}