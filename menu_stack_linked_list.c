#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL; // Initialize the top of the stack to NULL

void push(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Stack overflow.\n");
        return;
    }

    newNode->data = item;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto the stack.\n", item);
}

int pop() {
    if (top == NULL) {
        printf("Stack underflow: The stack is empty.\n");
        return -1;  // Return a sentinel value to indicate failure
    } else {
        struct Node* temp = top;
        int popped = temp->data;
        top = top->next;
        free(temp);
        return popped;
    }
}

int peek() {
    if (top == NULL) {
        printf("The stack is empty.\n");
        return -1;  // Return a sentinel value to indicate failure
    } else {
        return top->data;
    }
}

void display() {
    if (top == NULL) {
        printf("The stack is empty.\n");
    } else {
        struct Node* current = top;
        printf("Stack elements: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
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
