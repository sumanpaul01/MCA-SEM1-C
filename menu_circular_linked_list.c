#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode; // Initialize the next pointer to itself
    return newNode;
}

// Function to display the elements of the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("Head\n");
}

// Function to insert a node at the beginning of the circular linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode; // Point the new node to itself
        return newNode;
    }
    newNode->next = head;
    struct Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode; // Point the new node to itself
        return newNode;
    }
    struct Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return head;
}

// Function to delete a node from the beginning of the circular linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty. Nothing to delete.\n");
        return NULL;
    }
    if (head->next == head) { // If there's only one node
        free(head);
        return NULL;
    }
    struct Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = head->next;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end of the circular linked list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty. Nothing to delete.\n");
        return NULL;
    }
    if (head->next == head) { // If there's only one node
        free(head);
        return NULL;
    }
    struct Node* current = head;
    struct Node* previous = NULL;
    while (current->next != head) {
        previous = current;
        current = current->next;
    }
    previous->next = head;
    free(current);
    return head;
}

// Function to delete a node after a given node in the circular linked list
struct Node* deleteAfterNode(struct Node* head, int target) {
    if (head == NULL) {
        printf("Circular Linked List is empty. Nothing to delete.\n");
        return NULL;
    }
    struct Node* current = head;
    struct Node* previous = NULL;
    while (current->data != target) {
        previous = current;
        current = current->next;
        if (current == head) {
            printf("Node with data %d not found.\n", target);
            return head;
        }
    }
    if (current->next == head) {
        printf("No node to delete after %d.\n", target);
        return head;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

// Function to delete the entire circular linked list
void deleteList(struct Node* head) {
    if (head == NULL) {
        return;
    }
    struct Node* current = head;
    struct Node* temp;
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
}

int main() {
    struct Node* head = NULL;
    int choice, data, target;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Create a circular linked list\n");
        printf("2. Display the circular linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Delete a node from the beginning\n");
        printf("6. Delete a node from the end\n");
        printf("7. Delete a node after a given node\n");
        printf("8. Delete the entire circular linked list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data for the first node: ");
                scanf("%d", &data);
                head = createNode(data);
                printf("Circular Linked List created successfully.\n");
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 4:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 5:
                head = deleteFromBeginning(head);
                break;
            case 6:
                head = deleteFromEnd(head);
                break;
            case 7:
                printf("Enter the target data after which to delete: ");
                scanf("%d", &target);
                head = deleteAfterNode(head, target);
                break;
            case 8:
                deleteList(head);
                printf("Circular Linked List deleted.\n");
                break;
            case 9:
                deleteList(head);
                printf("Program exited.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
