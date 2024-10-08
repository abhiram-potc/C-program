#include<stdio.h>
#include<stdlib.h>
#define max 5
void push(void);
void pop(void);
void display(void);
int stack[max],top=-1;
int main()
{
    int c,d;
    char ch,x,y;
    system("clear");
    do
    {
        printf("Stack OPeration\n\n");
        printf("1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("wrong choice\n");
        }
        printf("\nDo you want to continue? (y/n)");
        scanf("%s",&ch);
    }
    while(ch=='Y'||ch=='y');
    return 0;
}
void push(void)
{
    int d;
    printf("Enter the element: ");
    scanf("%d",&d);
    if(top==max)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        stack[top]=d;
    }
}
void pop(void)
{
    int d;
    if(top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        d=stack[top];
        top--;
        printf("\nDeleted value: %d\n",d);

    }
}
void display(void)
{
    int i,d;
    if(top==-1)
    {
        printf("Underflow");
    }
    else
    {
        printf("Stack elements are:\n");
        for(i=0;i<top;i++)
        {
            if(i==0)
            {
                printf("%d  bottom\n",stack[i]);
            }
            else if(i==top)
            {
                printf("%d  top\n",stack[i]);
            }
            else
            {
                printf("%d\n",stack[i]);
            }
        }
    }
}