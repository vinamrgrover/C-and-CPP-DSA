#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define CAPACITY 5
int queue[CAPACITY];
void push();
void pop();
void display();
int rear=0, front=0;
int main()
{
    int ch;
    while(true)
    {
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("ENTER THE CHOICE: ");
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
    if(rear==CAPACITY)
    {
        printf("QUEUE IS FULL\n");
    }

    else
    {
        queue[rear]=n;
        rear++;
        printf("ELEMENT %d SUCCESSFULLY INSERTED INTO THE QUEUE\n", n);
    }
}

void pop()
{
    if(rear==front)
    {
        printf("THE QUEUE IS EMPTY\n");
    }

    else
    {
        int n=queue[front];
        for(int i=0; i<rear-1; i++)
        {
            queue[i]=queue[i+1];
        }
        printf("ELEMENT %d SUCCESSFULLY REMOVED FROM THE QUEUE\n", n);
        rear--;
    }
}

void display()
{
    if(rear==front)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        for(int i=0; i<rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}