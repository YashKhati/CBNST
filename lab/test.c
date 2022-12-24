#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of observation : ");
    scanf("%d",&n);
    float X[n] , Y[n];
    float sum_x,sum_y;
    printf("enter value of x : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&X[i]);
        sum_x += X[i];
    }
    printf("enter value of y : \n");

    for(int i=0;i<n;i++)
    {
        scanf("%f",&Y[i]);
        sum_y += Y[i];
    }
    float sumx2,sum_xy;
    for(int i=0;i<n;i++)
    {
        sum_xy += X[i]*Y[i];
        sumx2 += X[i]*X[i];
    }
    
}