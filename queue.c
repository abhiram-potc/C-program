#include <stdio.h>
#include <stdlib.h>

int main() {
    int c, d, size;
    system("clear");
    printf("***Queue Operations***\n\n");
    printf("Enter the size: ");
    scanf("%d", &size);
    int q[size], rear = -1, front = -1;

    while (1) {
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        
        switch (c) {
            // Insertion
            case 1:
                if (rear == size - 1) {
                    printf("Overflow\n");
                } else {
                    if (front == -1)
                        front = 0;
                    printf("Enter the data: ");
                    scanf("%d", &d);
                    rear++;
                    q[rear] = d;
                }
                break;

            // Deletion
            case 2:
                if ((front == -1) || (front > rear)) {
                    printf("Underflow\n");
                } else {
                    d = q[front];
                    printf("The deleted data: %d\n", d);
                    front++;
                    if (front > rear) {
                        front = -1; // Reset if the queue is empty
                        rear = -1;
                    }
                }
                break;

            // Display
            case 3:
                if ((front == -1) || (front > rear)) {
                    printf("Underflow\n");
                } else {
                    int temp = front;
                    printf("Front = %d\n", q[front]);
                    printf("Rear = %d\n", q[rear]);
                    printf("\nThe elements are:\n");
                    while (temp <= rear) {
                        printf("%d\n", q[temp]);
                        temp++;
                    }
                }
                break;

            // Exit
            case 4:
                printf("Exiting...!\n");
                exit(0);

            default:
                printf("Wrong choice!!\n");
        }
    }
    return 0;
}
