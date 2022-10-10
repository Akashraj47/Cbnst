#include<stdio.h>
#include<math.h>
int main(){
    int n;
    printf("Enter equation:- ");
    scanf("%d",&n);
    float arr[n][n+1];
    float ratio = 0;
    float res[n];
    printf("Enter Augmented Matrix\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n+1;j++){
            scanf("%f",&arr[i][j]);
        }
    }
    // Converting to upper traingular matrix
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(j > i){
                ratio = arr[j][i] / arr[i][i];
                for(int k = 0;k<n+1;k++){
                    arr[j][k] = arr[j][k] - (ratio * arr[i][k]);
                }
            }
        }
    }
    // printing upper Traingular Matrix
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n+1;j++){
            printf("%f ",arr[i][j]);
        }
        printf("\n");
    }
    // Backward Substition
    res[n-1] = ((arr[n-1][n]) / (arr[n-1][n-1]));
    float sum = 0;
    for(int i = n-2;i>=0;i--){
        sum = 0;
        for(int j = i+1;j<n;j++){
            sum += arr[i][j] * res[j];
        }
        res[i] = (arr[i][n] - sum) / arr[i][i];
    }
    // Printing values of roots
    printf("Roots are\n");
    for(int i = 0;i<n;i++){
        printf("%f\n",res[i]);
    }
}