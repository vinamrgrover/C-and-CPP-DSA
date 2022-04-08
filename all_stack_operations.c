#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define CAPACITY 5
void push();
int top=-1;
int stack[CAPACITY];
int isFull();
int pop();
void display();
int peek();
int isEmpty();
int main()
{
    int ch;
    while(true)
    {
        printf("\n1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY THE ELEMENTS OF THE STACK\n");
        printf("4. PEEK\n");
        printf("5. EXIT\n");
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
                int a=peek();
                printf("PEEKING INTO THE STACK: %d", a);
                break;
            }
            case 5:
            {
                exit(0);
            }
        }

    }
}
void push()
{
    if(isFull())
    {
        printf("THE STACK IS FULL\n");
    }
    else
    {
        top++;
        int n;
        printf("VALUE: ");
        scanf("%d", &n);
        stack[top]=n;
        printf("\nELEMENT SUCCESSFULLY PUSHED INTO THE STACK\n");
    }
}

int isFull()
{
    if(top==CAPACITY-1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int pop()
{
    int temp;
    if(isEmpty())
    {
        printf("THE STACK IS EMPTY\n");
    }
    else
    {
        temp=stack[top];
        top--;
        printf("\nELEMENT %d SUCCESSFULLY POPPED FROM THE STACK\n", temp);
    }

    return temp;

}

int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{

    if(top==-1)
    {
        printf("STACK IS EMPTY\n");
    }

    else
    {
        printf("\nDISPLAYING THE ELEMENTS IN THE STACK\n");

        for(int i=0; i<=top; i++)
        {
            printf("%d\n", stack[i]);
        }

    }

}

int peek()
{
    int temp=stack[top];
    return temp;
}
