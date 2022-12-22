// Linear curve fitting

#include<stdio.h>
int main(){
    int n;
    printf("Enter total number of data points:- ");
    scanf("%d",&n);
    float Ex = 0,Ey = 0,Exy = 0,Ex2 = 0;
    float arr[2][3];
    float a , b;
    printf("Enter data points:- \n");
    float x, y;
    for(int i = 0;i<n;i++){
        scanf("%f",&x);
        scanf("%f",&y);
        Ex += x;
        Ey += y;
        Exy += (x*y);
        Ex2 += (x*x);
    }
    arr[0][0] = n;
    arr[0][1] = Ex;
    arr[0][2] = Ey;
    arr[1][0] = Ex;
    arr[1][1] = Ex2;
    arr[1][2] = Exy;
    // diagonl traingular matrix:- 
    float ratio ;
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++){
            if(j != i){
                ratio = arr[i][i] / arr[j][i];
                for(int k = 0;k<3;k++){
                    arr[j][k] = arr[i][k] - (ratio * arr[j][k]);
                }
            }
        }
    }
    b = arr[1][2]  / arr[1][1];
    a = arr[0][2] / arr[0][0];
    printf("Equation is:- ");
    printf("y = %f + %fx",a,b);
    return 0;
    
}