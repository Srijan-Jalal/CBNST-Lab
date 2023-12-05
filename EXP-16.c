#include <stdio.h>
#include <math.h>

int main(void) 
{
    int n,i,k,it=0;

    printf("Enter the Total Number of Unknowns: ");
    scanf("%d",&n);

    float AdjM[n][n+1], y[n],e,er,ce,temp;

    printf("Enter The Pre-Specified Error: ");
    scanf("%f",&e);

    printf("Enter the Argumented Matrix:\n");
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

    printf("\nITERATION \t X \t Y \t Z \n");
    printf("%d \t\t",it);
    for(i = 1; i <= n; i++) 
    {
        printf("%.4f \t",y[i]);
    }
    printf("\n");
    do 
    {
        er = 0;
        printf("%d \t\t",++it);
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
            printf("%.4f\t",y[i]);
        }
        printf("\n");
    } while(er >= e);
    printf("\nSolution: \t");
    for(i = 1; i <= n; i++) 
    {
        printf("%.4f \t",y[i]);
    }
    printf("\n");
    return 0;
}