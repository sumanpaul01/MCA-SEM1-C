
#include <stdio.h>

int main() 
{
    int a,da,hra;
    printf("Enter Basic Salary: ");
    scanf("%d",&a);
    da=a*0.4;
    hra=a*0.2;
    printf("Ramesh's gross salary is :%d",a+da+hra);
    

    return 0;
}