#include <stdio.h>
#include <math.h>
int main(void)
{
    int n;
    printf("Straight Line Equation: Y = A + BX\n");
    printf("Enter the no. of values: ");
    scanf("%d",&n);
    float x[n],y[n],dx[n],dy[n],meanx=0,meany=0,a=0,b=0,c=0;
    printf("Enter the values of x: ");
    for(int i=0;i<n;i++)
        scanf("%f",&x[i]);
    printf("Enter the values of y: ");
    for(int i=0;i<n;i++)
        scanf("%f",&y[i]);
    printf("\nGiven Table is:\n");
    printf("X\t\t Y\t\t\n");
    for(int i=0;i<n;i++)
        printf("%.2f\t\t %.2f\n",x[i],y[i]);
    for(int i=0;i<n;i++)
    {
        meanx+=x[i];
        meany+=y[i];
    }
    meanx/=n;          
    meany/=n;           
    for(int i=0;i<n;i++)
    {
        a+=((x[i]-meanx)*(y[i]-meany));     
        b+=((x[i]-meanx)*(x[i]-meanx));
        c+=((y[i]-meany)*(y[i]-meany));
    }
    float pcc=a/(sqrt(b*c));        
    float sdx=sqrt(b/n);            
    float sdy=sqrt(c/n);           
    float B=pcc*(sdy/sdx);          
    float A=meany-(B*meanx);        
    printf("\nPearson's Correlation Coefficient: %.4f\n",pcc);
    printf("\nEquation is:\nY = %.4f + %.4fX",A,B);
    return 0;
}