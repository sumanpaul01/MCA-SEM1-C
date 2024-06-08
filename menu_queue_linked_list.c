#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define global pointers for front and rear of the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to enqueue an element into the queue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d enqueued successfully.\n", value);
}

// Function to dequeue an element from the queue
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        struct Node* temp = front;
        printf("%d dequeued successfully.\n", temp->data);
        
        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
        }

        free(temp);
    }
}

// Function to peek at the front element of the queue
void peek() {
    if (front == NULL) {
        printf("Queue is empty. Cannot peek.\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

// Function to display the elements of the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct Node* current = front;
        printf("Queue elements: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
