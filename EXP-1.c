#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void PFN(double a,double b,double c)
{
    printf("%.4fx^2 ",a);
    if(b>0)
        printf("+ %.4fx ",b);
    else    
        printf("%.4fx ",b);
    if(c>0)
        printf("+ %.4f=0\n",c);
    else    
        printf("%.4f=0\n",c);
}

void QR(double a,double b,double c)
{
    double D = b*b-4*a*c;
    double r1,r2,r;
    if(D>0)
    {
        D=sqrt(D);
        printf("Roots are Real and Distinct \n");
        printf("R1 = %.4lf \n",(-b+D)/2*a);
        printf("R2 = %.4lf \n",(-b-D)/2*a);
    }
    else if(D==0)
    {
        printf("Roots are Real and Equal \n");
        printf("R = %.4lf \n",-b/2*a);
    }
    else
    {
        D=sqrt(fabs(D));
        printf("Roots are Imaginery \n");
        printf("R1 = %.4lf + %.4lfi\n",(-b/2*a),(D/2*a));
        printf("R2 = %.4lf - %.4lfi\n",(-b/2*a),(D/2*a));
    }
}

int main(void)
{
    double a,b,c;
    do{
        printf("Enter The Co-efficient of x^2: ");
        scanf("%lf",&a);
    }while(a==0);
    printf("Enter The Co-efficient of x: ");
    scanf("%lf",&b);
    printf("Enter The Constant Value: ");
    scanf("%lf",&c);
    printf("Given Quadratic Equation is : ");
    PFN(a,b,c);
    QR(a,b,c);
    return 0;
}