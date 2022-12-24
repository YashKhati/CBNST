#include<stdio.h>
#include<math.h>


float fx(float x)
{
    return (-1*cos(x))+3*x-1;
}

float diff(float x)
{
    float ans = sin(x)+3;
    return ans; 
}
int main()
{
    float x0,x1,toll;
    while(1)
    {
        printf("Enter initial guess : (x0,x1) \n");
        scanf("%f%f",&x0,&x1);
        if(fx(x0)*fx(x1) < 0)
        {
            printf("Roots are valid\n");
            printf("Enter tollerable error : ");
            scanf("%f",&toll);
            break;
        }
        printf("Invalid input try again \n");
    }
    int maxitr,i=0;
    printf("Enter max number of itterations : ");
    scanf("%d",&maxitr);
    float x=(x0+x1)/2;
    do
    {
        i++;
        if(diff(x)==0)
        {
            printf("Method Failed (Divide by zero)");
            break;
        }
        x1=x-(fx(x)/diff(x));
        printf("Itteration i=%d\tx%d : %f\tx%d : %f\n",i,i-1,x,i,x1);
        if(fabs(fx(x1))<=toll)
        {
            break;   
        }
        x=x1;
    } while (i<=maxitr);   
}