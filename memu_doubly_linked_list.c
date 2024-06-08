#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void createDoublyLinkedList() {
    int n, data;
    struct Node* newNode, *temp;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    printf("Doubly linked list created successfully!\n");
}

void displayDoublyLinkedList() {
    struct Node* temp = head;
    
    if (temp == NULL) {
        printf("The doubly linked list is empty.\n");
        return;
    }
    
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Node inserted at the beginning.\n");
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Node inserted at the end.\n");
}

void insertBeforeNode(int data, int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Node with key %d not found.\n", key);
        return;
    }
    
    newNode->prev = temp->prev;
    newNode->next = temp;
    
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }
    
    temp->prev = newNode;
    printf("Node inserted before %d.\n", key);
}

void insertAfterNode(int data, int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Node with key %d not found.\n", key);
        return;
    }
    
    newNode->prev = temp;
    newNode->next = temp->next;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;
    printf("Node inserted after %d.\n", key);
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("The doubly linked list is empty. Nothing to delete.\n");
        return;
    }
    
    struct Node* temp = head;
    head = head->next;
    
    if (head != NULL) {
        head->prev = NULL;
    }
    
    free(temp);
    printf("Node deleted from the beginning.\n");
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("The doubly linked list is empty. Nothing to delete.\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    
    free(temp);
    printf("Node deleted from the end.\n");
}

void deleteAfterNode(int key) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Node with key %d not found or no node to delete after it.\n", key);
        return;
    }
    
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    
    if (toDelete->next != NULL) {
        toDelete->next->prev = temp;
    }
    
    free(toDelete);
    printf("Node deleted after %d.\n", key);
}

void deleteDoublyLinkedList() {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
    head = NULL;
    printf("Doubly linked list deleted.\n");
}

int main() {
    int choice, data, key;
    
    do {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Display Doubly Linked List\n");
        printf("3. Insert at the Beginning\n");
        printf("4. Insert at the End\n");
        printf("5. Insert Before a Node\n");
        printf("6. Insert After a Node\n");
        printf("7. Delete from Beginning\n");
        printf("8. Delete from End\n");
        printf("9. Delete After a Node\n");
        printf("10. Delete Entire Doubly Linked List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createDoublyLinkedList();
                break;
            case 2:
                displayDoublyLinkedList();
                break;
            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter key before which to insert: ");
                scanf("%d", &key);
                insertBeforeNode(data, key);
                break;
            case 6:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter key after which to insert: ");
                scanf("%d", &key);
                insertAfterNode(data, key);
                break;
            case 7:
                deleteFromBeginning();
                break;
            case 8:
                deleteFromEnd();
                break;
            case 9:
                printf("Enter key after which to delete: ");
                scanf("%d", &key);
                deleteAfterNode(key);
                break;
            case 10:
                deleteDoublyLinkedList();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 0);
    
    return 0;
}
