#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

// Push an element onto the stack
void push(int value) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = value;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

// Pop an element from the stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char expression[]) {
    int i, operand1, operand2, result;
    for (i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(expression[i] - '0');
        } else {
            operand2 = pop();
            operand1 = pop();
            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    exit(1);
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char expression[100];
    printf("Enter a postfix expression: ");
    gets(expression);  // Note: gets is not recommended for secure input, but it's used here for simplicity.

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
