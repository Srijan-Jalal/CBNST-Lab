#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double func(double x)
{
    return (pow(x,3)-(3*x)-5);
}
double fd(double x)
{
    return ((3*pow(x,2))-3);
}
double dis(double a, double b)
{
    if(abs(func(a)) > abs(func(b)))
        return b;
    else
        return a;
}

int main(void)
{
    double a,b,e,c,x;
    int i=1;
    printf("Given Equation is: 3x^3-3x-5=0 \n");
    do 
    {
        printf("Enter The Guess1: ");
        scanf("%lf",&a);
        printf("Enter The Guess2: ");
        scanf("%lf",&b);
    }while(func(a)*func(b)>0);
    printf("Enter The Pre-Specified Error: ");
    scanf("%lf",&e);
    c = dis(a,b);
    do
    {
        x = c-(func(c)/fd(c));
        printf("Iteration %d: %lf \n",i++,c);
        if(func(x)==0)
            break;
        else
            c=x;
    }while(fabs(func(c))>e);
    printf("Root is %lf \n", c);
    return 0;
}