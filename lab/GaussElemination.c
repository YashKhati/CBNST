#include<stdio.h>
int main()
{
   int n;
   printf("Enter number of unknowns : ");
   scanf("%d",&n);
   float a[n][n+1];
   printf("Enter argumented Matrix : \n");
   for(int i=0;i<n;i++)
   {
        for(int j=0;j<n+1;j++)
        {
            scanf("%f",&a[i][j]);
        }
   }
   
   // Upper triangular matrix
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<n+1;j++)
    {
        if(j<i)
        { 
            float ratio = a[i][j]/a[j][j];
            for(int k=0;k<n+1;k++)
            {
                a[i][k] = a[i][k]-ratio*(a[j][k]);
            }
        }
    }
   }

   printf("\nUpper triangular matrix : \n");
   for(int i=0;i<n;i++)
   {
        for(int j=0;j<n+1;j++)
        {
            printf("%0.2f\t",a[i][j]);
        }
        printf("\n");
   }
    printf("\n");

  // Backward substitution
    float ans[n];
    ans[n-1]=a[n-1][n]/a[n-1][n-1];

    for(int i=n-2; i >=0;i--)
    {
        float sum=0;
        for(int j=i+1;j<n;j++)
        {
            sum += a[i][j] * ans[j];
        }
        ans[i]=(a[i][n]-sum)/a[i][i];
    }
    
    printf("Values are - : \n");
    for(int i=0;i<n;i++)
    {
        printf("values of variables :%0.2f \n",ans[i]);
    }
}