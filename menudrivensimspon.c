//menu driven program for simpson 1/3rd and 3/8th
#include<stdio.h>
float f(float x)
{
    return (1/(1+x*x));
}
void simpson(int n,float a,float b)
{
    float sum = 0;
    int pos = 1;
    float h = (b-a)/n;
    sum = f(a)+f(b);
    for(int i=a+h;i<b;i=i+h)
    {
        if(pos %2 == 0)
        {
          sum += 2*f(i);
        }
        else
        {
           sum += 4*f(i);
        }
        pos++;
    }
    sum = (h*sum)/3;
    printf("Value of integral is %f\n",sum);
}
void simpson2(int n,float a,float b)
{
    float sum = 0;
    int pos = 1;
    float h = (b-a)/n;
    sum = f(a)+f(b);
    for(int i=a+h;i<b;i=i+h)
    {
       if(pos%3 ==0)
         sum = sum + 2*f(i);
       else
         sum = sum + 3*f(i); 
       pos++;   
    }
    sum = (3*h)/8 * sum;
    printf("Value of integral is %f\n",sum);
}
int main()
{
    int n;
    printf("Enter total number of intervals\n");
    scanf("%d",&n);
    float a,b;
    printf("Enter the value of a and b\n");
    scanf("%f",&a);
    scanf("%f",&b);
    int choice;
    int q = 1;
   while(q){
    printf("Enter your choice please\n");
    printf("Press 1 for simpson 1/3 and 2 for simpson 3/8 and press 3 for exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
           simpson(n,a,b);
           break;
        case 2:
           simpson2(n,a,b);
           break;
        case 3: 
           q = 0;
           break;
    }
   }
    return 0;
}
