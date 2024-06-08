#include <stdio.h>
void primeFactors(int num) {
    while (num % 2 == 0) {
        printf("2 ");
        num /= 2;
    }
    // Now num must be an odd number
    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
    }
    // If num is still greater than 1, it is a prime number
    if (num > 1) {
        printf("%d ", num);
    }
}
int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Prime factors of %d are: ", num);
    primeFactors(num);
    printf("\n");
    return 0;
}
