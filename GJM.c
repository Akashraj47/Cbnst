// Gauss Jordan Method

#include<stdio.h>
#include<math.h>
int main(){
    int n;
    printf("Enter number of equation:- ");
    scanf("%d",&n);
    float arr[n][n+1];
    float res[n];
    printf("Enter Augmented Matrix\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n+1;j++){
            scanf("%f",&arr[i][j]);
        }
    }
    // Converting into diagonal form
    float ratio = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(j != i){
                ratio = arr[j][i] / arr[i][i];
                for(int k = 0;k<n+1;k++){
                    arr[j][k] = arr[j][k] - (ratio * arr[i][k]);
                }
            }
        }
    }
    printf("\n");
    // printing Diagonal Matrix
    for(int i = 0;i<n;i++){
        for(int j= 0;j<n+1;j++){
            printf("%f ",arr[i][j]);
        }
        printf("\n");
    }
    // finding Roots
    printf("\nRoots are\n");
    for(int i = 0;i<n;i++){
        res[i] = arr[i][n] / arr[i][i];
        printf("%f\n",res[i]);
    }
    return 0;
}