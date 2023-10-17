#include<stdio.h>
#include<Math.h>
#include<stdlib.h>
double func(double x)
{
    return cos(x)+2*sin(x)+x*x;
}

double findc(double a,double b)
{
    return b - ((b-a)/(func(b)- func(a))*func(b));
}

int main()
{
    double a,b,e,c;
    int i=1,N;
    printf("Given Equation x^2+2sin(x)+cos(x)=0 \n");
    do 
    {
        printf("Enter The Guess1: ");
        scanf("%lf",&a);
        printf("Enter The Guess2: ");
        scanf("%lf",&b);
    }while(func(a)*func(b)>0);
    printf("Enter The Pre-Specified Error: ");
    scanf("%lf",&e);
    printf("Enter maximum iteration: ");
    scanf("%d",&N);
    do
    {
        c=findc(a,b);
        printf("Iteration %d: %.4lf \n",i++,c);
        a=b;
        b=c;
        if(i>N)
            break;
    } while (fabs(func(c))>e);
    printf("Root is %.4lf \n",c);
    return(0);
}