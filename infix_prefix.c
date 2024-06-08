#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool>

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

// Convert infix expression to prefix notation
void infixToPrefix(char infix[], char prefix[]) {
    int i, j;
    char token, rev_infix[MAX_SIZE];
    struct Stack stack;
    initialize(&stack);
    j = 0;

    // Reverse the infix expression
    for (i = strlen(infix) - 1; i >= 0; i--) {
        rev_infix[j++] = infix[i];
    }
    rev_infix[j] = '\0';

    // Modify the operator precedence for the Shunting Yard algorithm
    for (i = 0; rev_infix[i] != '\0'; i++) {
        if (rev_infix[i] == '(') {
            rev_infix[i] = ')';
            i++;
        } else if (rev_infix[i] == ')') {
            rev_infix[i] = '(';
            i++;
        }
    }

    j = 0;

    for (i = 0; rev_infix[i] != '\0'; i++) {
        token = rev_infix[i];
        if (isalnum(token)) {
            prefix[j++] = token;
        } else if (token == ')') {
            push(&stack, token);
        } else if (token == '(') {
            while (!isEmpty(&stack) && stack.items[stack.top] != ')') {
                prefix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] == ')') {
                pop(&stack);
            }
        } else {
            while (!isEmpty(&stack) && precedence(token) < precedence(stack.items[stack.top])) {
                prefix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    while (!isEmpty(&stack)) {
        prefix[j++] = pop(&stack);
    }

    prefix[j] = '\0';

    // Reverse the prefix expression to get the final result
    for (i = 0, j = strlen(prefix) - 1; i < j; i++, j--) {
        char temp = prefix[i];
        prefix[i] = prefix[j];
        prefix[j] = temp;
    }
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
