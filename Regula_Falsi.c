#include <stdio.h>
#include<math.h>
float equation(float x){
    // return (x*x*x)-(5*x)+1;
    return (3*x) + sin(x) - exp(x);
}
int main(){
    printf("Eqaution:- 3*x + sin(x) - e^x\n");
    float a,b;
    float err ;
    printf("Enter allowed error:- ");
    scanf("%f",&err);
    while(1){
        printf("Enter value of a:- ");
        scanf("%f",&a);
        printf("Enter value of b:- ");
        scanf("%f",&b);
        if(equation(a) * equation(b) < 0){
            printf("Roots are real\n");
            break;
        }
        else{
            printf("Invalid value of a and b please try again\n");
        }
    }
    int count = 0;
    float curr_root = 0;
    do{
        count++;
        curr_root = a - ((b - a) / (equation(b) - (equation(a)))) * equation(a);
        printf("Iteration no. %d --> Root at a = %f and b = %f is %f\n",count,a,b,curr_root);
        if(equation(a)*equation(curr_root)<0)
        {
            b = curr_root;
        }
        else
        {
            a = curr_root;
        }
    }while(fabs(equation(curr_root))>err);
    return 0;
}