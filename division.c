#include<stdio.h>
int main()
{
    int sub1,sub2,sub3,p;
    printf("Enter the marks of c programming: ");
    scanf("%d",&sub1);
    printf("Enter the marks of Discrete Math: ");
    scanf("%d",&sub2);
    printf("Enter the marks of DSA : ");
    scanf("%d",&sub3);
    p=(sub1+sub2+sub3)/3;
    if (p>=60)
    {
        printf("First Division");
    }
    else if(p>=50)
    {
        printf("Second Division");
    }
    else if(p>=40)
    {
        printf("Third Division");
    }
    else 
    {
        printf("Fail");
    }
    return 0;
}