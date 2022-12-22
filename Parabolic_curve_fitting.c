//parabolic curve fitting

#include<stdio.h>
int main(){
    int n;
    printf("Enter no. of data points:- ");
    scanf("%d",&n);
    float Ex = 0,Ey = 0,Ex2 = 0,Ex3 = 0,Ex4 = 0,Exy = 0,Ex2y = 0;
    float x,y;
    float res[3];
    float arr[3][4];
    printf("Enter data points:- \n");
    for(int i = 0;i<n;i++){
        scanf("%f",&x);
        scanf("%f",&y);
        Ex += x;
        Ey += y;
        Exy += (x*y);
        Ex2 += (x*x);
        Ex3 += (x*x*x);
        Ex4 += (x*x*x*x);
        Ex2y += (x*x*y);
    }
    arr[0][0] = n;
    arr[0][1] = Ex;
    arr[0][2] = Ex2;
    arr[0][3] = Ey;
    
    arr[1][0] = Ex;
    arr[1][1] = Ex2;
    arr[1][2] = Ex3;
    arr[1][3] = Exy;
    
    arr[2][0] = Ex2;
    arr[2][1] = Ex3;
    arr[2][2] = Ex4;
    arr[2][3] = Ex2y;
    
    
    float ratio = 0;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(j != i){
                ratio = arr[i][i] / arr[j][i];
                for(int k = 0;k<4;k++){
                    arr[j][k] = arr[i][k] - (ratio * arr[j][k]);
                }
            }
        }
    }
    
    // Diagonal Matrix:-  
    for(int i = 0;i<3;i++){
        for(int j = 0;j<4;j++){
            printf("%f ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    res[2] = arr[2][3] / arr[2][2];
    res[1] = arr[1][3] / arr[1][1];
    res[0] = arr[0][3] / arr[0][0];
    printf("Equation is:- ");
    printf("y = %f + (%f)x + (%f)x2\n",res[0],res[1],res[2]);
    return 0;
}