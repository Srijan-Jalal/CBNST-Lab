#include<stdio.h>
float INTG_func(float x)
{
    return (1/(1+x*x));
}
int main(void)
{
    int n;
    printf("Enter The No of Interval: ");
    scanf("%d",&n);
    float X[n+1],Y[n+1];
    printf("Enter the Lower Limit: ");
    scanf("%f",&X[0]);
    printf("Enter the Higher Limit: ");
    scanf("%f",&X[n]);
    float h = (X[n]-X[0])/n;
    Y[0] = INTG_func(X[0]);
    for(int i=1;i<n;i++)
    {
        X[i] = X[i-1]+h;
        Y[i] = INTG_func(X[i]);
    }
    Y[n] = INTG_func(X[n]);
    float sum = (Y[0] + Y[n]);
    float sum_3=0,Rsum=0;
    for(int i=1;i<n;i++)
    {
        if(i%3==0)
            sum_3+=Y[i];
        else
            Rsum+=Y[i];
    }
    for(int j=0;j<n+1;j++)
        printf("X[%d]=%.2f \t Y[%d]=%.2f \n",j,X[j],j,Y[j]);
        
    printf("The Answer is: %.4f ",(3*h/8)*(sum+2*sum_3+3*Rsum));
    return 0;
}