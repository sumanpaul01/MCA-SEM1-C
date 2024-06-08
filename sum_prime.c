#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0; // 0 and 1 are not prime numbers
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Not a prime number
        }
    }

    return 1; // It is a prime number
}

int main() {
    int n, sum = 0;

    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }

    printf("The sum of prime numbers between 1 and %d is %d\n", n, sum);

    return 0;
}
