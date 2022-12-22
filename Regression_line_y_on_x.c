// Regression Line y on x
#include<stdio.h>
int main(){
    int n;
    printf("Enter data points:- ");
    scanf("%d",&n);
    float x,y,Ex = 0,Ey = 0,Ex2 = 0,Exy;
    for(int i = 0;i<n;i++){
        scanf("%f",&x);
        scanf("%f",&y);
        Ex += x;
        Ey += y;
        Ex2 += (x*x);
        Exy += (x*y);
    }
    float byx = (n*Exy - (Ex*Ey)) / (n*Ex2 - (Ex * Ex));
    float x_bar = 0 , y_bar = 0;
    x_bar = Ex / n;
    y_bar = Ey / n;
    float c = (y_bar - byx*x_bar);
    printf("Regression line is:- ");
    printf("y = (%f)x + %f",byx,c);
}