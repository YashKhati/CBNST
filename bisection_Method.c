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

// 2 way

#include<stdio.h>
float findValueAt(float x)
{
   return x*x*x - 2*x -5;
}

float bisect(float x1,float x2)
{
    return (x1+x2)/2;
}

int main()
{
    int maxIteration,i=1;
    float x1,x2,x;
    printf("Enter Maximum no of Iterations\n");
    scanf("%d",&maxIteration);

//......Compute x1 and x2............. 
   
   do
   {
        printf("Enter the value of x1 and x2(starting boundary)");
        scanf("%f%f",&x1,&x2);
        if(findValueAt(x1)*findValueAt(x2)>0)
        {
           printf("Roots are Invalid\n");
           continue;
        }
        else
        {
            printf("Roots Lie between %f and %f\n",x1,x2);
            break;

        }
    } while(1);

 //..........Find root............   
   //x1 x2 ->finalised
    while(i<=maxIteration)
    {
      x = bisect(x1,x2);   //find the mid point
      if(findValueAt(x)*findValueAt(x1)<0)
         x2=x;  //x2 is shifted   
      else if(findValueAt(x)*findValueAt(x2)<0)
         x1=x;  //x1 is shifted
     printf("Iterations=%d  Roots=%f\n",i,x);   
      
      i++; 
    }
    printf("Root=%f  Total Iterations=%d",x,--i);

    return 0;
}

//Bisection Method (With Allowed Error Concept)
#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001
float findValueAt(float x)
{
   return x*x*x - 2*x -5;
}

float bisect(float x1,float x2)
{
    return (x1+x2)/2;
}
int main()
{
    int maxIteration,i=1;
    float x1,x2,x3,x;
    printf("Enter Maximum no of Iterations\n");
    scanf("%d",&maxIteration);
    
   do
   {
        printf("Enter the value of x1 and x2(starting boundary->Initial Roots)");
        scanf("%f%f",&x1,&x2);
        if(findValueAt(x1)*findValueAt(x2)>0)
        {
           printf("Roots are Invalid\n");
           continue;
        }
        else
        {
            printf("Roots Lie between %f and %f\n",x1,x2);
            break;

        }
    } while(1);

    //find the mid point
    x = bisect(x1,x2);   

    do
    {
      if(findValueAt(x)*findValueAt(x1)<0)
         x2=x;    
      else
         x1=x;
      printf("Iterations=%d  Roots=%f\n",i,x);   
      x3 = bisect(x1,x2);  
      if(fabs(x3-x)<EPSILON)
      {
          //print root
          printf("Root=%f  Total Iterations=%d",x,i);
          return 0;

      }
      x=x3;  //v.imp
      i++; 
    }while(i<=maxIteration);
    printf("Root=%f  Total Iterations=%d",x,--i);

    return 0;
}
