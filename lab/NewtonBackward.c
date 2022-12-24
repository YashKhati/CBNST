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

    for(int col =2;col<n+1 ; col++)
    {
        for(int row=0;row<n-col+1;row++)
        {
            mat[row][col]=mat[row+1][col-1]-mat[row][col-1];
        }
    }

    printf("newton Difference table : \n");
    for(int row =0 ;row<n; row++)
    {
        for(int col=0 ; col<=n-row;col++)
        {
            printf("%f\t",mat[row][col]);
        }
        printf("\n");
    }

    float u , y ,u1,fact=1;
    int j=2;
    u=(x-mat[n-1][0])/(mat[1][0]-mat[0][0]);
    u1=u;
    y=  mat[n-1][1];

    for(int i=n-2;i>=0;i--)
    {
        y= y + (u1*mat[i][j])/fact;
        u1 = u1*(u+(j-1));
        fact=fact*j;
        j++;
    }
     printf("Value of x at %f is = %f",x,y);
}