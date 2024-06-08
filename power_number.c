#include <stdio.h>

int main() {
    double base, exponent, result = 1.0;

    printf("Enter the base: ");
    scanf("%lf", &base);
    printf("Enter the exponent: ");
    scanf("%lf", &exponent);

    for (int i = 1; i <= exponent; i++) {
        result *= base;
    }

    printf("%.2lf ^ %.2lf = %.2lf\n", base, exponent, result);

    return 0;
}
