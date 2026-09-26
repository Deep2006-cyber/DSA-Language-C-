#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *tail = NULL;

void createlist() {
    int n, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        if (tail == NULL) {
            tail = newnode;
            newnode->next = newnode;
        } else {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
    }

    printf("Successfully created\n");
}

void display() {
    if (tail == NULL) {
        printf("List is empty..!\n");
        return;
    }

    struct node *temp = tail->next;

    printf("Circular linked list: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);

    printf("back to first node\n");
}

void insert_at_beg() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (tail == NULL) {
        tail = newnode;
        newnode->next = newnode;
    } else {
        newnode->next = tail->next;
        tail->next = newnode;
    }

    printf("Successfully inserted\n");
}

void insert_at_end() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (tail == NULL) {
        tail = newnode;
        newnode->next = newnode;
    } else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }

    printf("Successfully inserted\n");
}

void insert_at_pos() {
    int pos, i;
    struct node *newnode, *temp;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (tail == NULL) {
        if (pos == 1) {
            tail = newnode;
            newnode->next = newnode;
            printf("Successfully inserted\n");
        } else {
            printf("Invalid position\n");
            free(newnode);
        }
        return;
    }

    if (pos == 1) {
        newnode->next = tail->next;
        tail->next = newnode;
        printf("Successfully inserted\n");
        return;
    }

    temp = tail->next;

    for (i = 1; i < pos - 1 && temp != tail; i++) {
        temp = temp->next;
    }

    if (i != pos - 1) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    if (temp == tail) {
        tail = newnode;
    }

    printf("Successfully inserted\n");
}

void det_at_beg() {
    struct node *temp;

    if (tail == NULL) {
        printf("List is empty..!\n");
        return;
    }

    temp = tail->next;

    if (tail == temp) {
        tail = NULL;
    } else {
        tail->next = temp->next;
    }

    free(temp);

    printf("Successfully deleted\n");
}

void det_at_end() {
    struct node *temp, *prev;

    if (tail == NULL) {
        printf("List is empty..!\n");
        return;
    }

    if (tail->next == tail) {
        free(tail);
        tail = NULL;
    } else {
        temp = tail->next;

        while (temp->next != tail) {
            temp = temp->next;
        }

        prev = temp;
        temp = tail;

        prev->next = tail->next;
        tail = prev;

        free(temp);
    }

    printf("Successfully deleted\n");
}

void det_at_pos(int pos) {
    int i;
    struct node *temp, *nextnode;

    if (tail == NULL) {
        printf("List is empty..!\n");
        return;
    }

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        det_at_beg();
        return;
    }

    temp = tail->next;

    for (i = 1; i < pos - 1 && temp != tail; i++) {
        temp = temp->next;
    }

    if (temp == tail) {
        printf("Invalid position\n");
        return;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;

    if (nextnode == tail) {
        tail = temp;
    }

    free(nextnode);

    printf("Successfully deleted\n");
}

int main() {
    int a, pos;

    while (1) {
        printf("\n1. Create list\n");
        printf("2. Display list\n");
        printf("3. Insertion at beginning\n");
        printf("4. Insertion at end\n");
        printf("5. Insertion at position\n");
        printf("6. Deletion at beginning\n");
        printf("7. Deletion at end\n");
        printf("8. Deletion at position\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &a);

        switch (a) {
            case 1:
                createlist();
                break;

            case 2:
                display();
                break;

            case 3:
                insert_at_beg();
                break;

            case 4:
                insert_at_end();
                break;

            case 5:
                insert_at_pos();
                break;

            case 6:
                det_at_beg();
                break;

            case 7:
                det_at_end();
                break;

            case 8:
                printf("Enter position: ");
                scanf("%d", &pos);
                det_at_pos(pos);
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}