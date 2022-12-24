#include<stdio.h>
#include<math.h>

float fun(float x)
{
    return (x*log10(x) - 1.2);
}
int main()
{
    float x0,x1;
    while(1)
    {
        printf("Enter value of xo and x1 : \n");
        printf("Xo = ");
        scanf("%f",&x0);
        printf("X1 = ");
        scanf("%f",&x1);
        if(fun(x0)*fun(x1) < 0)
        {
            printf("Roots lies between %0.2f and %0.2f\n",x0,x1);
            break;
        }
        printf("\nInvalid Roots\n");
        printf("\nEnter values again \n");
    }
    float tol;
    printf("Enter tollerance : ");
    scanf("%f",&tol);
    float x2;
    int i=1;
    do
    {
        x2 = ( (x0*fun(x1)) - (x1 *fun(x0)) ) / (fun(x1) - fun(x0));
        printf("Itteration : %d\t x : %f\t fun(x) : %f\n",i,x2,fun(x2));
        if(f(un(x2) * fun(x0)) < 0)
        {
            x0 = x2;
        }
        else
        {
            x1 = x2;
        }
        
        if(fabs(x1-x0)<tol)
        {
            break;
        }
        i++;
    } while (fabs(x1-x0)>tol);
    printf("Toatal itteration %d\t x: %f",i,x2);
}