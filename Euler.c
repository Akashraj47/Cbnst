#include<stdio.h>
float f(float x,float y)
{
    return ((x-y)/(y+x));
}
int main()
{
    float x0,y0,x;
    printf("Enter the value of x0\n");
    scanf("%f",&x0);
    printf("Enter the value of y0\n");
    scanf("%f",&y0);
    printf("Enter the value of x for which you want to find the value\n");
    scanf("%f",&x);
    float h;
    float y=y0;
    printf("Enter the value of h\n");
    scanf("%f",&h);
    for(float i = x0;i<=x-h;i=i+h)
    {
        printf("X = %f and y = %f\n",i,y);
        y = y+(h*f(i,y));
    }
    printf("Value is %f",y);
}