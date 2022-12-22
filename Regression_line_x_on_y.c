// Regression line x on y
#include<stdio.h>
int main(){
    int n;
    printf("Enter data points:- ");
    scanf("%d",&n);
    float x,y,Ex= 0,Ey = 0,Exy = 0,Ey2 = 0;
    printf("Enter data points:- \n");
    for(int i = 0;i<n;i++){
        scanf("%f",&x);
        scanf("%f",&y);
        Ex += x;
        Ey += y;
        Ey2 += (y*y);
        Exy += (x*y);
    }
    float bxy = ((n*Exy) - (Ex*Ey)) / ((n*Ey2) - (Ey * Ey));
    float y_bar = Ey / n;
    float x_bar = Ex / n;
    float c = x_bar - (bxy * y_bar);
    printf("equation is:- ");
    printf("x = (%f)y + (%f)\n",bxy,c);
}