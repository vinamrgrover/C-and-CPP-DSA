#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define CAPACITY 5
int queue[CAPACITY];
int rear=-1, front=-1;
int size=CAPACITY;
void push();
void pop();
void display();
int main()
{
    int ch;

    while(true)
    {
        printf("\n1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                exit(0);
            }
        }
    }
}

void push()
{
    int n;
    printf("ENTER THE VALUE: ");
    scanf("%d", &n);

    if((rear==size-1 && front==0)||front==rear+1)
    {
        printf("QUEUE IS FULL\n");
    }

    else if(rear==-1&&front==-1)
    {
        rear=front=0;
        queue[rear]=n;
        printf("ELEMENT %d SUCCESSFULLY INSERTED INTO THE QUEUE\n", n);
    }
    else if(rear==size-1)
    {
        rear=0;
        queue[rear]=n;
        printf("ELEMENT %d SUCCESSFULLY INSERTED INTO THE QUEUE\n", n);
    }
    else
    {
        rear++;
        queue[rear]=n;
        printf("ELEMENT %d SUCCESSFULLY INSERTED INTO THE QUEUE\n", n);
    }
}

void pop()
{
    if(rear==-1&&front==-1)
    {
        printf("THE QUEUE IS EMPTY\n");
    }

    else if(rear==front)
    {
        int n;
        n=queue[front];
        printf("ELEMENT %d SUCCESSFULLY REMOVED FROM THE QUEUE\n", n);
        rear=front=-1;
    }
    else if(front==size-1)
    {
        int n;
        n=queue[front];
        printf("ELEMENT %d SUCCESSFULLY REMOVED FROM THE QUEUE\n", n);
        front=0;
    }

    else
    {
        int n;
        n=queue[front];
        printf("ELEMENT %d SUCCESSFULLY REMOVED FROM THE QUEUE\n", n);
        front++;
    }
}

void display()
{
    if(rear==-1 && front==-1)
    {
        printf("NO ELEMENTS IN THE QUEUE\n");
    }

    else if(rear>=front)
    {
        for(int i=front; i<=rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }

    else  // if we have removed some elements from the queue by using the pop function and the front is greater than the rear
    {
        for(int i=0; i<=rear; i++)
        {
            printf("%d ", queue[i]);
        }

        for(int i=front; i<=size-1; i++)  // if some of the elements are removed from the middle of the queue by the help of the pop function
        {
            printf("%d ", queue[i]);
        }
    }
}