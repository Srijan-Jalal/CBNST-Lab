#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double func(double x)
{
    return (pow(x,3)-(2*x)-5);
}

double findc(double a,double b)
{
    return ((a*func(b) - b*func(a))/(func(b)- func(a)));
}

int main(void)
{
    double a,b,c,e;
    int ic=1;
    printf("Given Equation is: x^3-2x-5=0\n");
    do{
        printf("Enter The Guess1: ");
        scanf("%lf",&a);
        printf("Enter The Guess2: ");
        scanf("%lf",&b);
    }while(func(a)*func(b) > 0);

    printf("Enter The Pre-Specified Error: ");
    scanf("%lf",&e);
    do
    {
        c = findc(a,b);
        printf("Iteration %d: %lf \n",ic,c);
        if(func(a)*func(c)<0)
            b=c;

        else if(func(c)*func(b)<0)
            a=c;

        else
            break;
        ic++;

    }while(fabs(func(c))>e);
    printf("Root is %lf. \n",c);
    return 0;
}