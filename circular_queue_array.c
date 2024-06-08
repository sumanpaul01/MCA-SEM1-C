#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX_SIZE);
}

int isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Circular Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        circularQueue[rear] = value;
        printf("%d enqueued successfully.\n", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Circular Queue is empty. Cannot dequeue.\n");
    } else {
        printf("%d dequeued successfully.\n", circularQueue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

void peek() {
    if (isEmpty()) {
        printf("Circular Queue is empty. Cannot peek.\n");
    } else {
        printf("Front element: %d\n", circularQueue[front]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Circular Queue is empty.\n");
    } else {
        printf("Circular Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", circularQueue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Menu:\n");
        printf("i. Enqueue\n");
        printf("j. Dequeue\n");
        printf("k. Peek\n");
        printf("l. Display\n");
        printf("m. Exit\n");
        printf("Enter your choice: ");
        char option;
        scanf(" %c", &option);

        switch (option) {
            case 'i':
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 'j':
                dequeue();
                break;
            case 'k':
                peek();
                break;
            case 'l':
                display();
                break;
            case 'm':
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
