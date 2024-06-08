#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter First Number:");
    scanf("%d",&a);
    printf("Enter Second Number:");
    scanf("%d",&b);
    if (a>b)
    {
        printf("%d is maximum",a);
    }
    else if(b>a)
    {
        printf("%d is maximum",b);
    }
    else
    {
        printf("Both are equal");
    }

    return 0;
}