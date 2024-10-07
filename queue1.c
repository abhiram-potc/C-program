#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size;
    char ch;
    printf("Enter queue size: ");
    scanf("%d",&size);
    int queue[size], front=-1, rear=-1,data,i,c;
    system("clear");
    do
    {
        printf("***Queue Operation***\n\n");
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            //insertion
            case 1:
            if(rear==size-1)
            {
                printf("Overflow\n");
            }
            else
            {
                if(front==-1)
                front++;
                printf("Enter the data: ");
                scanf("%d",&data);
                rear++;
                queue[rear]=data;
            }
            break;

            //deletion
            case 2:
            if((front==-1)||(front>rear))
            {
                printf("Underflow\n");
            }
            else
            {
                data=queue[front];
                printf("Deleted value: %d",data);
                front++;
            }
            break;

            //display
            case 3:
            printf("Front = %d\n",queue[front]);
            printf("Rear = %d\n",queue[rear]);
            printf("The entered data are:\n");
            while(front<=rear)
            {
                printf("%d\n",queue[front]);
                front++;
            }
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Wrong choice!!!");
        }
        printf("\nDo you want to continue? y/n: ");
        scanf("%s",&ch);
    }
    while(ch=='Y'||ch=='y');
    return 0;
}
