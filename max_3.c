#include<stdio.h>
int main()
{
  int a,b,c;
    printf("Enter First Number:");
    scanf("%d",&a);
    printf("Enter Second Number:");
    scanf("%d",&b);
    printf("Enter Third  Number:");
    scanf("%d",&c);
    if (a>b && a>c)
    {
        printf("%d is maximum",a);
    }
    else if (b>a && b>c)
    {
        printf("%d is maximum",b);
    }
    else if (c>b && c>a)
    {
        printf("%d is maximum",c);
    }
    else 
    {
        printf("All number are equal");
    }
    return 0;
}