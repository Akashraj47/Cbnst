#include<stdio.h>
#include<math.h>
float equation(float x){
    return x*x*x - 3*x -5;
    // return (x*x*x) - (5*x) + 1;
    // return (x - cos(x));
    // return (3*x) + sin(x) - exp(x);
}
int main(){
    float a,b,c;
    float all_err;
    int count = 1;
    while(1){
        printf("Enter first value:- ");
        scanf("%f",&a);
        printf("Enter second value:- ");
        scanf("%f",&b);
        if(equation(a) * equation(b) < 0){
            break;
        }
        else{
            printf("Wrong value,please try again\n");
        }
    }
    printf("Enter allowed error\n");
    scanf("%f",&all_err);
    do{
        c = (a + b) / 2;
        printf("At count = %d Root = %f\n",count,c);
        count++;
        if(equation(a) * equation(c) < 0){
            b = c;
        }
        else{
            a = c;
        }
    }while(fabs(equation(c)) > all_err);
    return 0;
}