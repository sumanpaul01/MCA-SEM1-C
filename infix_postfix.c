#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure for the stack
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push an item onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Pop an item from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0'; // Return null character to indicate failure
    }
    return stack->items[stack->top--];
}

// Get the precedence of an operator
int precedence(char operator) {
    if (operator == '^') {
        return 3;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '+' || operator == '-') {
        return 1;
    } else {
        return 0;
    }
}

// Convert infix expression to postfix notation
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initialize(&stack);
    int i, j;
    char token;
    j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        token = infix[i];
        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&stack, token);
        } else if (token == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            if (stack.top != -1 && stack.items[stack.top] != '(') {
                printf("Invalid expression\n");
                return;
            } else {
                pop(&stack);
            }
        } else {
            while (stack.top != -1 && precedence(token) <= precedence(stack.items[stack.top])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
