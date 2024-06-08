#include<stdio.h>
int main()
{
    float a;
    printf("Enter a Number: ");
    scanf("%f",&a);
    if (a<0.0)
    {
        printf("%f is negative number",a);
    }
    return 0;
}