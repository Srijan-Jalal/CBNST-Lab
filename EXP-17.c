#include <stdio.h>
#include <math.h>
int main(void)
{
    int n;
    printf("Straight Line Eqn: \n");
    printf("Y = A + BX \n");
    printf("Enter The Number Of Data: ");
    scanf("%d",&n);
    int AdjM[n][4],X_sum=0,Y_sum=0,XY_sum=0,X2_sum=0;
    printf("Enter The Values:\n");
    printf("X Y\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&AdjM[i][0]);
        X_sum += AdjM[i][0];
        scanf("%d",&AdjM[i][1]);
        Y_sum += AdjM[i][1];
        AdjM[i][2] = AdjM[i][0] * AdjM[i][1];
        XY_sum += AdjM[i][2];
        AdjM[i][3] = AdjM[i][0] * AdjM[i][0];
        X2_sum += AdjM[i][3];
    }
    float fac = (float)X_sum/n,A,B;
    printf("Given Table Is: \n");
    printf("\t------------------------------\n");
    printf("\t|X\t|Y\t|XY\t|X^2\n");
    printf("\t------------------------------\n");
    for(int i=0;i<n;i++)
    {
        printf("\t|%d\t|%d\t|%d\t|%d\n",AdjM[i][0],AdjM[i][1],AdjM[i][2],AdjM[i][3]);
    }
    printf("\t------------------------------\n");
    printf("SUM \t|%d\t|%d\t|%d\t|%d\n",X_sum,Y_sum,XY_sum,X2_sum);
    printf("\t------------------------------\n");
    printf("Eqn-1: %dA + %dB = %d\n",n,X_sum,Y_sum);
    printf("Eqn-2: %dA + %dB = %d\n",X_sum,X2_sum,XY_sum);
    B = (XY_sum - (Y_sum * fac))/(X2_sum - (X_sum * fac));
    A = (Y_sum - (X_sum * B))/n;
    printf("Y = %.4f + %.4fX \n",A,B);
    return 0;
}