#include<stdio.h>
float fun(float a,float b)
{
    return (a+b);
}
int main()
{
    float x0,y0;
    printf("Enter initial value of x and y : ");
    scanf("%f%f",&x0,&y0);
    float n,xn,yn;
    printf("enter last value of x : ");
    scanf("%f",&xn);
    printf("Enter number of steps : ");
    scanf("%f",&n);
    float h = (xn-x0)/n;
    float slope=0;
    printf("\n x \t\t yn-1 \t\t\t slope \t\t\t y\n");
    for(int i = 0 ; i < n ; i++)
    {
        slope = f(x0,y0);
        yn = y0 + (h*slope);
        
        printf("%0.4f \t\t %0.4f \t\t %0.4f \t\t %0.4f\n",x0,y0,slope,yn);
        y0=yn;
        x0=x0+h;
    }
    
}