#include<stdio.h>
#include<math.h>
float equation(float x){
    // return (x*x*x) - (5*x) + 1;
    // return (x - cos(x));
    return (3*x) + sin(x) - exp(x);
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
            printf("Invalid Input! press try again");
        }
    }
    printf("Enter allowed error:- ");
    scanf("%f",&all_err);
    do{
        c = a - ((b - a) / (equation(b) - equation(a))) * equation(a);
        printf("At count = %d Root is %f\n",count,c);
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