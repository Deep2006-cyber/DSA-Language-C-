
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;  // Global head pointer

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// I) Creation of a linked list
void createList(int n) {
    int value, i;
    struct Node* temp;
    head = NULL;

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
}

// II) Display the list
void displayList() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// III) Insertion at beginning
void insertBeginning(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// IV) Insertion at end
void insertEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// V) Insertion after a given location
void insertAfterPosition(int pos, int value) {
    struct Node* temp = head;
    int i;
    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

// VI) Deletion from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// VII) Deletion from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted element: %d\n", temp->data);
    free(temp);
    prev->next = NULL;
}

// VIII) Deletion from a given location
void deleteFromPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;

    if (pos == 1) {
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    int i;
    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Menu-driven main function
int main() {
    int choice, n, value, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert After Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete from Position\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 5:
                printf("Enter position after which to insert: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insertAfterPosition(pos, value);
                break;
            case 6:
                deleteBeginning();
                break;
            case 7:
                deleteEnd();
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}