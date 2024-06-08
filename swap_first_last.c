//Wap to swap first and last digit of a number
#include <stdio.h>
#include <math.h>
int main()
{
     long int n;
     int first, end, swap, digit, divide;
     printf("Enter the number :--> ");//for eg: 5623
     scanf("%ld", &n);
     digit = log10(n);  // 3
     divide = pow(10,digit); //1000
     first = n / divide; //5
     n = n % divide; //623
     end = n % 10; //3
     n = n / 10; //562
     swap = end * divide + n * 10 + first;  //3 * 1000 + 623 * 10 + 5
     printf("Swap value is : %d", swap);
     return 0;
}