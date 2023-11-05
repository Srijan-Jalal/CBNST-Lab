#include<stdio.h>
int main(void)
{
	float xp, yp=0, p;
	int i,j,n;
	printf("Enter number of data: ");
	scanf("%d", &n);
    float x[n], y[n];
	printf("Enter data:\n");
	for(i=1;i<=n;i++)
	{
		printf("x[%d] = ", i);
		scanf("%f", &x[i]);
	    printf("y[%d] = ", i);
		scanf("%f", &y[i]);
	}
	printf("Enter interpolation point: ");
	scanf("%f", &xp);
	for(i=1;i<=n;i++)
	{
		p=1;
		for(j=1;j<=n;j++)
			if(i!=j)
			    p = p* (xp - x[j])/(x[i] - x[j]);
		yp = yp + p * y[i];
	}
	printf("Interpolated value at %.3f is %.3f.", xp, yp);
}
