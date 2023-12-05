#include <stdio.h>
#include <math.h>

int main(void) 
{
    int n,i,k;

    printf("Enter the Total Number of Equations: ");
    scanf("%d", &n);

    float AdjM[n][n+1], y[n],e,er,ce,temp;

    printf("Enter The Pre-Specified Error: ");
    scanf("%f", &e);

    printf("Enter the Argumented Matrix: \n");
    for(i = 1; i <= n; i++) 
    {
        for(k = 1; k <= n + 1; k++) 
        {
            scanf("%f", &AdjM[i][k]);
        }
    }
    
    for(i = 1; i <= n; i++) 
    {
        y[i] = 0;
    }
    
    do 
    {
        er = 0;
        for(i = 1; i <= n; i++) 
        {
            float sum = 0;
            for(k = 1; k <= n; k++) 
            {
                if(k != i) {
                    sum = sum + AdjM[i][k] * y[k];
                }
            }
            temp = (AdjM[i][n + 1] - sum) / AdjM[i][i];
            ce = fabs(y[i] - temp);
            if(ce > er) {
                er = ce;
            }
            y[i] = temp;
            printf("Y[%d] = %f\n", i, y[i]);
        }
    } while(er >= e);
    
    printf("\nSolution\n");
    for(i = 1; i <= n; i++) {
        printf("Y[%d]: %f\n", i, y[i]);
    }
    
    return 0;
}



// #include <stdio.h>
// #include <math.h>
// #include <stdbool.h>

// float findx(float y,float z);
// float findy(float z,float x);
// float findz(float x,float y);

// int main(void)
// {
//     float x=0,y=0,z=0;
//     int i=0,N;
//     printf("Given Equations are: \n");
//     printf("3x + 1y + 1z = 8 \n");
//     printf("2x + 3y + 1z = 11 \n");
//     printf("1x + 2y + 3z = 14 \n");
//     printf("Enter The Number Of Interations: ");
//     scanf("%d",&N);
//     printf("Iteration \tX \t\t Y \t\t Z \n");
//     do{
//         printf("%d \t\t%.4f \t\t %.4f \t %.4f \n",i,x,y,z);

//         x = findx(y,z);
//         y = findy(z,x);
//         z = findz(x,y);
//         i++;

//     }while(i<=N);
//     printf("Solution is: \t%.4f \t\t %.4f \t %.4f \n",x,y,z);
//     return 0;
// }

// float findx(float y,float z)
// {
//     return (8-y-z)/3;
// }

// float findy(float z,float x)
// {
//     return (11-z-(2*x))/3;
// }

// float findz(float x,float y)
// {
//     return (14-(2*y)-x)/3;
// }