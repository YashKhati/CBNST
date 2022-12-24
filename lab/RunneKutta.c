#include<stdio.h>
#define fun(x,y) x+y
int main()
{
    float x0,y0;
    printf("Enter initial values of x and y \n");
    scanf("%f%f",&x0,&y0);
    float xn;
    printf("Enter xn : ");
    scanf("%f",&xn);
    float st,n;
    printf("Enter number of step size : ");
    scanf("%f",&st);
    n=(xn-x0)/st;
    float y,k1,k2,k3,k4,yn;
    for(int i=0;i<n;i++)
    {
        k1=st*(fun(x0,y0));
        k2=st*(fun((x0+st/2),(y0+k1/2)));
        k3=st*(fun((x0+st/2),(y0+k2/2)));
        k4=st*(fun((x0+st),(y0+k3)));

        y=(k1+k4+ (2*(k2+k3)))/6;
        yn=y0+y;
        printf("%f\t%f\t%f\t%f\t%f\t%f\t%f\n",x0,y0,y,k1,k2,k3,k4);
        x0=x0+st;
        y0=yn;
    }
      printf("\n Value of y at n = %0.4f is %0.4f", xn ,y);
}