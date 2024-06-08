#include <stdio.h>

// Function to compute and print the Fibonacci series
void printFibonacci(int n, int a, int b) {
    if (n > 0) {
        printf("%d ", a);  // Print the current Fibonacci number
        printFibonacci(n - 1, b, a + b);  // Recursively call with the next numbers in the series
    }
}

int main() {
    int n;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Fibonacci Series: ");
        printFibonacci(n, 0, 1);
        printf("\n");
    }

    return 0;
}
