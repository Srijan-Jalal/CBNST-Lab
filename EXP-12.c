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
    float b,a;
    printf("Enter the Lower Limit: ");
    scanf("%f",&a);
    printf("Enter the Higher Limit: ");
    scanf("%f",&b);
    float h = (b-a)/n;
    X[0] = a;
    Y[0] = INTG_func(X[0]);
    for(int i=1;i<n;i++)
    {
        X[i] = a+(i*h);
        Y[i] = INTG_func(X[i]);
    }
    X[n]=b;
    Y[n] = INTG_func(X[n]);
    float sum = (Y[0] + Y[n]);
    float Esum=0,Osum=0;
    for(int i=1;i<n;i++)
    {
        if(i%2==0)
            Esum+=Y[i];
        else
            Osum+=Y[i];
    }
    for(int j=0;j<n+1;j++)
        printf("X[%d]=%.2f \t Y[%d]=%.2f \n",j,X[j],j,Y[j]);
        
    printf("The Answer is: %.4f ",(h/3)*(sum+2*Esum+4*Osum));
    return 0;
}