#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
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
    newNode->next = NULL;
    return newNode;
}

// Function to display the elements of the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert a node before a given node in the linked list
struct Node* insertBeforeNode(struct Node* head, int data, int target) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    if (head->data == target) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data != target) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Node with data %d not found.\n", target);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

// Function to insert a node after a given node in the linked list
struct Node* insertAfterNode(struct Node* head, int data, int target) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Node with data %d not found.\n", target);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

// Function to delete a node from the beginning of the linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("Linked List is empty. Nothing to delete.\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

// Function to delete a node from the end of the linked list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("Linked List is empty. Nothing to delete.\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    return head;
}

// Function to delete a node after a given node in the linked list
struct Node* deleteAfterNode(struct Node* head, int target) {
    if (head == NULL) {
        printf("Linked List is empty. Nothing to delete.\n");
    } else {
        struct Node* current = head;
        while (current != NULL && current->data != target) {
            current = current->next;
        }
        if (current == NULL || current->next == NULL) {
            printf("Node with data %d not found or there is no node after it.\n", target);
        } else {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        }
    }
    return head;
}

// Function to delete the entire linked list
void deleteList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
}

int main() {
    struct Node* head = NULL;
    int choice, data, target;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Create a linked list\n");
        printf("2. Display the linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node before a given node\n");
        printf("6. Insert a node after a given node\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data for the first node: ");
                scanf("%d", &data);
                head = createNode(data);
                printf("Linked List created successfully.\n");
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
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the target data before which to insert: ");
                scanf("%d", &target);
                head = insertBeforeNode(head, data, target);
                break;
            case 6:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the target data after which to insert: ");
                scanf("%d", &target);
                head = insertAfterNode(head, data, target);
                break;
            case 7:
                head = deleteFromBeginning(head);
                break;
            case 8:
                head = deleteFromEnd(head);
                break;
            case 9:
                printf("Enter the target data after which to delete: ");
                scanf("%d", &target);
                head = deleteAfterNode(head, target);
                break;
            case 10:
                deleteList(head);
                printf("Linked List deleted.\n");
                break;
            case 11:
                deleteList(head);
                printf("Program exited.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
