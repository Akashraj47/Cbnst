#include<stdio.h>
#include<math.h>
float eq(float x){
    return (x*x*x) - (5*x) + 1;
}
float diff_eq(float x){
    return (3*x*x) - 5;
}
float h(float x){
    return eq(x) / diff_eq(x);
}
int main(){
    float all_err;
    float a,c1,c2;
    int count = 1;
    while(1){
        printf("Enter a value:- ");
        scanf("%f",&a);
        if(diff_eq(a) == 0){
            printf("Invalid input please try again\n");
        }
        else{
            break;
        }
    }
    printf("Enter allowed error:- ");
    scanf("%f",&all_err);
    do{
        c1 = a - h(a);
        printf("At count = %d root = %f\n",count,c1);
        count++;

        c2 = c1 - h(c1);
        printf("At count = %d root = %f\n",count,c2);
        count++;

        a = c2;

    }while(fabs(c2 - c1) > all_err);
    return 0;
}