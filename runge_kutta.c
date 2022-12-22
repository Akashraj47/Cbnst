#include<stdio.h>
float function(float x,float y){
    return (x-y)/(x+y);
}
int main()
{
    int i,n;
    float x0,y0,h,xn,k1,k2,k3,k4,x,y,k;
    printf("Enter the value of x0:\n");
    scanf("%f",&x0);
    printf("Enter the value of y:\n");
    scanf("%f",&y0);
    printf("Enter the value of h:\n");
    scanf("%f",&h);
    printf("Enter the value of xn:\n");
    scanf("%f",&xn);
    n = (xn-x0)/h;
    x = x0;
    y = y0;
    for(i = 0;i<n;i++)
    {
        k1 = h*function(x,y);
        k2 = h*function(x+h/2.0,y+k1/2.0);
        k3 = h*function(x+h/2.0,y+k2/2.0);
        k4 = h*function(x+h,y+k3);
        k = (k1+(k2+k3)*2.0+k4)/6.0;
        printf("\nX = %f , Y = %f",x,y);
        x = x+h;
        y = y+k;
    }
    printf("\nThe value for the differential equation ((x-y)/(x+y)) is as follow\n");
    printf("X = %f\nY = %f\n",x,y);
    return 0;
}