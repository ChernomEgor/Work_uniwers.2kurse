#include <stdio.h>
float main()
{
    float a;
    float b;
    float c;
    printf("Введите значение переменной a: \n");
    scanf("%f",&a);
    printf("Введите значение переменной b: \n");
    scanf("%f",&b);
    printf("Введите значение переменной c: \n");
    scanf("%f",&c);
    
    float x = (c-b)/a;
    printf("x = %f\n", x);
}
