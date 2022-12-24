#include<stdio.h>
#include<math.h>
#define EP 0.001
int n;
float findSum(int i,float arr[n][n+1],int n)
{
    float sum=0;
    for(int j=0;j<=n;j++)
    {
        if(i!=j)
        {
            sum+=arr[i][j];
        }
    }
    return sum;
}


int main()
{
    printf("Enter number of unknowns : ");
    scanf("%d",&n);
    int max_itr;
    printf("Enter max number of itterations : ");
    scanf("%d",&max_itr);
    float arr[n+1][n+1];

    printf("Enter Argumented matrix :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            scanf("%f",&arr[i][j]);
        }
    }

    // Check if method is applicable
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(fabs(arr[i][j]) > findSum(i,arr,n))
            {
                break;
            }
            else
            {
                printf("Gauss Jordan Not Applicable\n");
                return 0;
            }
        }
    }

    float ans_old[n];
    float ans_new[n];
    for(int i=0;i<n;i++)
    {
        ans_old[i]=0;
    }


    for(int i=1;i<max_itr;i++)
    {
        float sum =0;


        for(int i=0;i<n;i++)
        {
            sum=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    sum += arr[i][j]*ans_old[j];
                }
            }
            ans_new[i]=(arr[i][n]-sum)/arr[i][i];
        }


        int flag = 0;
        for(int i=0;i<n;i++)
        {
            if(ans_old[i]-ans_new[i] < EP)
            {
                continue;
            }
            else
            {
                flag =1;
                break;
            }
        }
        if(flag == 0)
        {
            for(int i=0;i<n;i++)
            {
                printf("x%d = %f",i,ans_new[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            ans_old[i]=ans_new[i];
        }

    }
}