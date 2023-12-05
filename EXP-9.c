#include<stdio.h>
float u_cal(float,int);
int fact(int);
int main(void)
{
    int i,j,n,val;
    printf("Enter number of data: ");
    scanf("%d", &n);
    float x[n], y[n][n];
    printf("Enter data:\n");
    for(i = 0; i < n ; i++)
    {
        printf("x[%d]=", i+1);
        scanf("%f", &x[i]);
        printf("y[%d]=", i+1);
        scanf("%f", &y[i][0]);
    }

    for(i = 1; i < n; i++)
        for(j = n-1; j > i-1; j--)
            y[j][i] = y[j][i-1] - y[j-1][i-1];

    printf("\nBACKWARD DIFFERENCE TABLE\n\n");
    for(i = 0; i < n; i++)
    {
        printf("%0.2f", x[i]);
        for(j = 0; j <= i ; j++)
        {
            printf("\t%0.2f", y[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter The Interpollation point: ");
    scanf("%d",&val);
    float sum = y[n - 1][0];
    float u = (val - x[n - 1]) / (x[1] - x[0]);
    for (int i = 1; i < n; i++)
        sum = sum + (u_cal(u, i) * y[n - 1][i]) /fact(i);
    printf("Value at %d is: %.4f \n",val,sum);
    return 0;
}
float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u + i);
    return temp;
}
int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}