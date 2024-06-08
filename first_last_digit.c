#include <stdio.h>
int main()
{
    int n, sum=0, fDigit, lDigit;
    printf("Enter number = ");
    scanf("%d", &n);
    // Find last digit of a number
    lDigit = n % 10;
    //Find the first digit by dividing n by 10 until n greater then 10
    while(n >= 10)
    {
        n = n / 10;
    }
    fDigit = n;
    printf("first digit = %d and last digit = %d\n\n", fDigit,lDigit);
    return 0;
}