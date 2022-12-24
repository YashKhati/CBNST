#include<stdio.h>
#include<stdlib.h>
float fun(float x)
{
    return (1.0/(10+(x*x*x)));
}
int main()
{
    int n;
    printf("Enter number of intervals : ");
    scanf("%d",&n);
    float h;
    float a,b;
    printf("Enter value of a and b : ");
    scanf("%f%f",&a,&b);
    h=(b-a)/n;
    float sum;
    sum=fun(a)+fun(b);
    float i;
    for(i = a+h; i<b; i+=h);
    {
        sum += 2 * fun(i);
    }
    sum = (sum*h)/2;
    printf("Value of integral : %f",sum);
}
