#include <stdio.h>

int main() {
    int n ; 
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    int space, num;
    
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (space = 1; space <= n - i; space++) {
            printf("  ");
        }
        
        // Print numbers
        num = 1;
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("%d", num);
            num++;
        }
        
        printf("\n");
    }
    
    return 0;
}