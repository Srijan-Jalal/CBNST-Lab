#include<stdio.h>
#include<math.h>
double func(double x)
{
    return (pow(x,3)-x-1);
}
int main(void)
{
    double a,b,c,e;
    int i=1;
    printf("Given Equation is: x^3-x-4=0 \n");
    do
    {
        printf("Enter The Guess1: ");
        scanf("%lf",&a);
        printf("Enter The Guess2: ");
        scanf("%lf",&b);
    }while(func(a)*func(b)>0);
    printf("Enter The Pre-Specified Error: ");
    scanf("%lf",&e);
    do{
        c = (a+b)/2;
        printf("Iteration %d:%lf \n",i,c);
        if(func(a)*func(c)<0)
            b=c;
        else if(func(a)*func(c)>0)
            a=c;
        else
            break;
        i++;
    }while(fabs(func(c)) > e);
    printf("Root is %lf ",c);
    return 0;
}