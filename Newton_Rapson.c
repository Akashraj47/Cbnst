/* Newton-Raphson Method
 19/09/2022

 f(x)= 3x - cos x -1
 f'(x) = 3 + sin x

 */

#include <stdio.h>
#include <math.h>

float func(float x)
{
    return (3 * x - cos(x) - 1);
}

float diff_func(float x)
{
    return (3 + sin(x));
}

float h(float x)
{
    return (func(x) / diff_func(x));
}

int main()
{
    float x0, x1, x2, err;
    int iter = 1;

    printf("Enter the value of x0: ");
    scanf("%f", &x0);

    if (diff_func(x0) == 0)
    {
        printf("f'(%f) = 0. \t The method fails. \nTry again with another value of x0.", x0);
        return -1;
    }

    printf("\nEnter the allowed error: ");
    scanf("%f", &err);

    do
    {
        x1 = x0 - h(x0);
        printf("\nIteration= %d \t Root %f", iter++, x1);

        x2 = x1 - h(x1);
        printf("\nIteration= %d \t Root %f", iter++, x2);

        x1 = x2;
    } while ((x2 - x1) > err);

    printf("\nIteration= %d \t Root= %f \n", iter, x1);
    return 0;
}