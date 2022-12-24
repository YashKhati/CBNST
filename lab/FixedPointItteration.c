#include<stdio.h>
#include<math.h>

float fx(float x)
{
    return (cos(x)-(3*x)+1);
}
float diff(float x)
{
    return ((sin(x)/3)*-1);
}
float Fix(float x)
{
    return (cos(x)+1)/3;
}
int main()
{
    float x,tol;
    while(1)
    {
        printf("Enter value of x : \n");
        scanf("%f",&x);
        if(Fix(x) < 1)
        {
            printf("%0.2f is Valid Input \n",x);
            printf("Enter tollerable error : ");
            scanf("%f",&tol);
            break;
        }
        printf("Invalid input Try again \n");
    }
    int i=0;
    float x1;
    do
    {
        i++;
        x1=Fix(x);
        printf("Itteration %d\t x%d : %f\t x%d : %f\n",i,i-1,x,i,x1);
        x=x1;
    } while (fabs(fx(x1))>tol);
    printf("Total itteration = %d\t X = %f\n",i,x1);
}