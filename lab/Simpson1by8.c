#include<stdio.h>
float fun(float x)
{
    return (1.0)/(1+(x*x));
}
int main()
{
    int n;
    printf("enter number of intervals : ");
    scanf("%d",&n);
    float a,b;
    printf("Enter value of a and b : ");
    scanf("%f%f",&a,&b);
    float h;
    h=(b-a)/n;
    float sum;
    sum = fun(a)+fun(b);
    float i;
    int count = 1;
    for(i=i+h;i<b;i+=h)
    {
        if(count%3==0)
        {
            sum += 2*fun(i);
        }
        else
        {
            sum += 3*fun(i);
        }
        count++;
    }
    sum = (h*sum*3)/8;
    printf("Value of integral : %f",sum);
}