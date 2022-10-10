#include<stdio.h>
#include<math.h>
float f(float x){
    return x*x*x - 3*x -5;
    // return (x*x*x) - (5*x) + 1;
    // return (x - cos(x));
}
int main(){
    float all_err;
    float a,b,c1,c2;
    int count = 1;
    printf("Enter first value:- ");
    scanf("%f",&a);
    printf("Enter second value:- ");
    scanf("%f",&b);
    printf("Enter allowed errer:- ");
    scanf("%f",&all_err);
    do{
        c1 = b - (((b - a) / (f(b) - f(a))) * f(b));
        printf("At count = %d root = %f\n",count,c1);
        count++;

        c2 = c1 - (((c1 - b) / (f(c1) - f(b))) * f(c1));
        printf("At count = %d root = %f\n",count,c2);
        count++;

        if(c1 == c2){
            printf("Failing Condition\n");
            return -1;
        }

        a = c1;
        b = c2;
    }while(fabs(c2 - c1) > all_err);
    return 0;
}