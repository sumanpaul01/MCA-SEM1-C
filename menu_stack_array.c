#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push element onto the stack.\n");
    } else {
        stack[++top] = item;
        printf("%d pushed onto the stack.\n", item);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
        return -1;  // Return a sentinel value to indicate failure
    } else {
        int popped = stack[top--];
        return popped;
    }
}

int peek() {
    if (top == -1) {
        printf("The stack is empty.\n");
        return -1;  // Return a sentinel value to indicate failure
    } else {
        return stack[top];
    }
}

void display() {
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push an element onto the stack\n");
        printf("2. Pop an element from the stack\n");
        printf("3. Peek at the top element\n");
        printf("4. Display stack elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1) {
                    printf("Popped element: %d\n", item);
                }
                break;
            case 3:
                item = peek();
                if (item != -1) {
                    printf("Top element: %d\n", item);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
