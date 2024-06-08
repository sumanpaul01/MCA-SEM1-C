#include <stdio.h>


int findGCD(int num1, int num2) {
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int main() {
    int num1, num2, lcm;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int gcd = findGCD(num1, num2);

    lcm = (num1 * num2) / gcd;

    printf("The LCM of %d and %d is %d\n", num1, num2, lcm);

    return 0;
}
