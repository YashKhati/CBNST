#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of unknowns : ");
    scanf("%d",&n);
    float arr[n][n+1];
    printf("Enter values of argumented matrix : ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            scanf("%f",&arr[i][j]);
        }
    }

    // Change to identity of diagonal matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i!=j)
            {
                float ratio = arr[j][i]/arr[i][i];
                for(int k=0;k<n+1;k++)
                {
                    arr[j][k]=arr[j][k]-ratio*arr[i][k];               
                }
            }
        }

    }

    for(int i=0;i<n;i++)
    {
        printf("Value of x%d : %f\n",i,arr[i][n]/arr[i][i]);
    }
}
