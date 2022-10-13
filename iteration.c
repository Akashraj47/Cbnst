#include<stdio.h>
#include<math.h>
float equation(float x){
    // return ((x*x*x) + 1) / 5;
    // return (1.0/2.0) * (log10(x) + 7);
}
float diff_equation(float x){
    // return (3*(x*x)) / 5;
    // return fabs((1.0/2.0) * (1/x) * (0.4343));
}
int main(){
    float a,c1,c2;
    float all_err;
    int count = 1;
    while(1){
        printf("Enter first value\n");
        scanf("%f",&a);
        if(fabs(diff_equation(a)) < 1){//diff_equation instead of equation
            break;
        }
    }
    printf("Enter allowed error\n");
    scanf("%f",&all_err);
    do{
        c1 = equation(a);
        printf("At count = %d Root = %f\n",count,c1);
        count++;

        c2 = equation(c1);
        printf("At count = %d Root = %f\n",count,c2);
        count++;

        a = c2;
    }while(fabs(c2 - c1) > all_err);
    return 0;
}
