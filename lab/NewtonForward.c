#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter number of terms : ");
    scanf("%d",&n);
    
    float mat[n][n+1];
    printf("Enter value of X \n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&mat[i][0]);
    }
    printf("Enter value of Y \n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&mat[i][1]);
    }

    float x;
    printf("Enter value of x for which you want y : ");
    scanf("%f",&x);

    // Difference table
    for(int col=2;col<n+1;col++)
    {
        for(int row=0;row<n-col+1;row++)
        {
            mat[row][col]=mat[row+1][col-1] - mat[row][col-1];
        }
    }   
    printf("Lagrenges Differentiation Table : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n-i;j++)
        {
            printf("%f\t",mat[i][j]);
        }
        printf("\n");
    }

    float u,y,u1,fact=1;
    u = (x-mat[0][0])/(mat[1][0]-mat[0][0]);

    y=mat[0][1];
    u1=u;
    for(int i=2;i<=n;i++)
    {
        y=y+(u1 * mat[0][i])/fact;
        fact = fact *i;
        u1 = u1*(u-(i-1));  
    }
    printf("Value of x at %f is = %f",x,y);

}