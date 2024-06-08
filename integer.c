#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter second number: ");
    scanf("%d",&b);
    if (a>b)
    {
        printf("%d is greater than %d",a,b);
    }
    else if(a<b)
    {
        printf("%d is less than %d",a,b);

    }
    else{
        printf("%d is equal %d",a,b);
    }

    return 0;
}