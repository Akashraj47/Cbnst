// Gauss seidal Method

#include<stdio.h>
#include<math.h>
int terminate(float res[],float temp[],int n,float all_err){
    int flag = 0;
    for(int i =0;i<n;i++){
        if(fabs(res[i] - temp[i]) > all_err){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    printf("Enter number of equation:- ");
    scanf("%d",&n);
    float arr[n][n+1];
    float res[n];
    float temp[n];
    float all_err = 0,sum = 0;
    int flag = 0;
    printf("Enter Augmented Matrix:\n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n+1;j++){
            scanf("%f",&arr[i][j]);
        }
    }
    for(int i = 0;i<n;i++){
        res[i] = 0;
    }
    printf("Enter allowed error:- ");
    scanf("%f",&all_err);
    // Checking for diagonal Dominant
    for(int i= 0;i<n;i++){
        sum = 0;
        for(int j = 0;j<n;j++){
            if(j != i){
                sum += fabs(arr[i][j]);
            }
        }
        if(fabs(arr[i][i]) > sum){
            flag = 0;
        }
        else{
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        printf("Augmented Matrix is not diagonal Dominant");
    }
    else{
        do{
            for(int i = 0;i<n;i++){
                temp[i] = res[i];
            }
            for(int i = 0;i<n;i++){
                sum = 0;
                for(int j = 0;j<n;j++){
                    if(j != i){
                        sum += arr[i][j] * res[j];
                    }
                }
                res[i] = (arr[i][n] - sum) / arr[i][i];
            }
        }while(terminate(res,temp,n,all_err) == 0);
        // printing result
        printf("\nRoots are:\n");
        for(int i = 0;i<n;i++){
            printf("%0.2f\n",res[i]);
        }
    }
    return 0;
}