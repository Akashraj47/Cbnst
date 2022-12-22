#include<stdio.h>
int main()
{
    int n;
    printf("Enter total number of observations\n");
    scanf("%d",&n);
    float arr[n][n+1];
    printf("Enter the values of x\n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&arr[i][0]);
    }
    printf("Enter the values of y\n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&arr[i][1]);
    }
    for(int j=2;j<n+1;j++)
    {
        for(int i=0;i<n-j+1;i++)
            arr[i][j] = arr[i+1][j-1]-arr[i][j-1];
    }
    printf("The Difference Table is as follows:\n");
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<=n-i;j++)
        printf("%f ",arr[i][j]);
     printf("\n");
    }
    int choice;
    float u,u1,y,fact,x;
    int q = 1;
  while(q){
    printf("Choices available\n1.Newton forward\n2.Newton Backward\n3.exit\n");
    printf("Enter your choice please\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
          printf("Enter the value of x at which you want to find the value\n");
          scanf("%f",&x);
          u= (x - arr[0][0])/(arr[1][0]-arr[0][0]);
          y=arr[0][1]; 
          u1=u;
          fact=1;
          for(int i=2;i<=n;i++)
         {
           y=y+(u1*arr[0][i])/fact;
           fact=fact*i; 
           u1=u1*(u-(i-1));
         }
           printf("\n\nValue at X=%g is = %f", x,y);
          break;
        case 2:
          printf("Enter the value of x at which you want to find the value\n");
          scanf("%f",&x);
          u= (x - arr[n-1][0])/(arr[1][0]-arr[0][0]);
          y=arr[n-1][1]; 
          u1=u;
          fact=1;
          int j=2;  
          for(int i=n-2;i>=0;i--)
          {
              y=y+(u1*arr[i][j])/fact;
              fact=fact*j; 
              u1=u1*(u+(j-1));
              j++;
           }
           printf("\n\nValue at X=%g is = %f", x,y);
          break;
        case 3:
           q = 0;
           break;
    }
    }
}
