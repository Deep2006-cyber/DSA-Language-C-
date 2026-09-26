#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *tail = NULL;

void createnode(int n) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = n;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
        tail = newnode;
    }
    else {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

void printLL() {
    struct node *temp = head;

    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void insert_begining(int n) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = n;
    newnode->prev = NULL;

    if (head == NULL) {
        newnode->next = NULL;
        head = tail = newnode;
    }
    else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insert_end(int n) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = n;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = tail = newnode;
    }
    else {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

void insert_any_position(int data, int pos) {
    int count = 1;
    struct node *newnode;
    struct node *temp = head;

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insert_begining(data);
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    while (count < pos - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    else {
        tail = newnode;
    }

    temp->next = newnode;
}

void deletion_at_beg() {
    struct node *temp;

    if (head == NULL) {
        printf("No node found\n");
        return;
    }

    temp = head;

    if (head == tail) {
        head = tail = NULL;
    }
    else {
        head = head->next;
        head->prev = NULL;
    }

    free(temp);
}

void deletion_at_end() {
    struct node *temp;

    if (head == NULL) {
        printf("No node found\n");
        return;
    }

    temp = tail;

    if (head == tail) {
        head = tail = NULL;
    }
    else {
        tail = tail->prev;
        tail->next = NULL;
    }

    free(temp);
}

void deletion_at_any_pos(int pos) {
    int count = 1;
    struct node *temp = head;

    if (head == NULL) {
        printf("No node found\n");
        return;
    }

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        deletion_at_beg();
        return;
    }

    while (count < pos && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp == tail) {
        deletion_at_end();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

void reverse() {
    struct node *temp = NULL;
    struct node *current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    temp = head;
    head = tail;
    tail = temp;
}

int main() {
    int m, x, a, y;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &m);

    for (int i = 1; i <= m; i++) {
        printf("\nEnter the element of %d node: ", i);
        scanf("%d", &x);
        createnode(x);
    }

    while (1) {
        int k = 0;

        printf("\n\n1. Insert at the beginning");
        printf("\n2. Insert at position");
        printf("\n3. Insert at the end");
        printf("\n4. Print the Linked List");
        printf("\n5. Delete at the beginning");
        printf("\n6. Delete at position");
        printf("\n7. Delete at the end");
        printf("\n8. Reverse");
        printf("\n9. Exit");

        printf("\n\nEnter an option: ");
        scanf("%d", &a);

        switch (a) {

            case 1:
                printf("\nEnter the data: ");
                scanf("%d", &k);
                insert_begining(k);
                break;

            case 2:
                printf("\nEnter the position: ");
                scanf("%d", &y);

                printf("Enter the data: ");
                scanf("%d", &k);

                insert_any_position(k, y);
                break;

            case 3:
                printf("\nEnter the data: ");
                scanf("%d", &k);
                insert_end(k);
                break;

            case 4:
                printLL();
                break;

            case 5:
                deletion_at_beg();
                break;

            case 6:
                printf("\nEnter the position: ");
                scanf("%d", &y);
                deletion_at_any_pos(y);
                break;

            case 7:
                deletion_at_end();
                break;

            case 8:
                reverse();
                printf("\nList reversed successfully\n");
                break;

            case 9:
                exit(0);

            default:
                printf("\nInvalid input");
        }
    }

    return 0;
}