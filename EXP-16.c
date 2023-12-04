#include <stdio.h>
#include <math.h>
#include <stdbool.h>

float findx(float y,float z);
float findy(float z,float x);
float findz(float x,float y);

int main(void)
{
    float x=0,y=0,z=0;
    int i=0,N;
    printf("Given Equations are: \n");
    printf("3x + 1y + 1z = 8 \n");
    printf("2x + 3y + 1z = 11 \n");
    printf("1x + 2y + 3z = 14 \n");
    printf("Enter The Number Of Interations: ");
    scanf("%d",&N);
    printf("Iteration \tX \t\t Y \t\t Z \n");
    do{
        printf("%d \t\t%.4f \t\t %.4f \t %.4f \n",i,x,y,z);

        x = findx(y,z);
        y = findy(z,x);
        z = findz(x,y);
        i++;

    }while(i<=N);
    printf("Solution is: \t%.4f \t\t %.4f \t %.4f \n",x,y,z);
    return 0;
}

float findx(float y,float z)
{
    return (8-y-z)/3;
}

float findy(float z,float x)
{
    return (11-z-(2*x))/3;
}

float findz(float x,float y)
{
    return (14-(2*y)-x)/3;
}