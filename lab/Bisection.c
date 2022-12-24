#include<stdio.h>
#include<math.h>
float fun(float x)
{
    return (x*log10(x) - 1.2);
}
int main()
{
    float a,b;
    while(1)
    {
        printf("Enter value of xo and x1 : \n");
        printf("Xo = ");
        scanf("%f",&a);
        printf("X1 = ");
        scanf("%f",&b);
        if(fun(a)*fun(b) < 0)
        {
            printf("Roots lies between %0.2f and %0.2f\n",a,b);
            break;
        }
        printf("\nInvalid Roots\n");
        printf("\nEnter values again \n");
    }
    float tol;
    int i = 1 ;
    printf("Enter tollerance value : ");
    scanf("%f",&tol);
    float x3,x;
    do
    {
        x = (a+b)/2.0;
        if(fun(a)*fun(x) < 0 )
        {
            b = x;
        }   
        else
        {
            a=x;
        }
        printf("Itteration : %d\tx : %f\tf(x) : %f\n",i,x,fun(x));
        if(fabs(b-a)<tol)
        {
            break;
        }
        i++;
    } while (fabs(b-a)>tol);
    
    printf("Roots are : %f Total Iterations: %d ",x,i);
    return 0;
}