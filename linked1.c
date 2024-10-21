#include <stdio.h>
#include <stdlib.h>

void insert(void);
void ins_beg(void);
void ins_loc(void);
void ins_end(void);
void delete(void);
void del_beg(void);
void del_loc(void);
void del_end(void);
void display(void);
int length(void);

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL;

int main() {
    int c;
    system("clear");
    printf("***Linked List***\n\n");
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Length\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Length of the list: %d\n", length());
                break;
            case 5:
                printf("Program exited...!\n");
                break;
            default:
                printf("Enter a valid choice!!!\n");
        }
    } while (c != 5);
    return 0;
}

void insert() {
    int c;
    printf("\n1. Insert in beginning\n2. Insert at end\n3. Insert at location\n4. Cancel\n");
    printf("Enter your choice: ");
    scanf("%d", &c);
    switch(c) {
        case 1:
            ins_beg();
            break;
        case 2:
            ins_end();
            break;
        case 3:
            ins_loc();
            break;
        default:
            printf("\nInvalid choice\n");
    }
}

void ins_beg() {
    struct node *temp;
    int value;
    printf("\nEnter the data: ");
    scanf("%d", &value);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = head;
    head = temp;
}

void ins_end() {
    struct node *temp, *q;
    int value;
    printf("Enter the data: ");
    scanf("%d", &value);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        q = head;
        while (q->link != NULL) {
            q = q->link;
        }
        q->link = temp;
    }
}

void ins_loc() {
    struct node *temp, *q;
    int value, loc, i;
    printf("\nEnter the data: ");
    scanf("%d", &value);
    printf("Enter the location (1-based index): ");
    scanf("%d", &loc);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;

    if (loc == 1) {
        temp->link = head;
        head = temp;
    } else {
        q = head;
        for (i = 1; i < loc - 1 && q != NULL; i++) {
            q = q->link;
        }
        if (q == NULL) {
            printf("Location is out of bounds. Insertion failed\n");
            free(temp);
        } else {
            temp->link = q->link;
            q->link = temp;
        }
    }
}

void delete() {
    int c;
    printf("\n1. Delete from beginning\n2. Delete from end\n3. Delete from location\n4. Cancel\n");
    printf("Enter your choice: ");
    scanf("%d", &c);
    switch (c) {
        case 1:
            del_beg();
            break;
        case 2:
            del_end();
            break;
        case 3:
            del_loc();
            break;
        default:
            printf("\nInvalid choice\n");
    }
}

void del_beg() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->link;
    printf("Deleted value: %d\n", temp->data);
    free(temp);
}

void del_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp, *q;
    q = head;
    while (q->link->link != NULL) {
        q = q->link;
    }
    temp = q->link;
    q->link = NULL;
    printf("Deleted value: %d\n", temp->data);
    free(temp);
}

void del_loc() {
    int loc, i;
    printf("Enter the location of the node that you want to delete: ");
    scanf("%d", &loc);
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp, *q;
    q = head;
    for (i = 1; i < loc - 1 && q != NULL; i++) {
        q = q->link;
    }
    if (q == NULL || q->link == NULL) {
        printf("Location is out of bounds. Deletion failed\n");
        return;
    }
    temp = q->link;
    q->link = temp->link;
    printf("Deleted value: %d\n", temp->data);
    free(temp);
}

void display() {
    struct node *q;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    q = head;
    while (q != NULL) {
        printf("%d  ", q->data);
        q = q->link;
    }
    printf("\n");
}

int length() {
    int count = 0;
    struct node *temp;
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->link;
    }
    return count;
}