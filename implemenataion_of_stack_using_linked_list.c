#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top;
void push();
void display();
int main()
{
    char ch='Y';
    while(ch=='Y')
    {
        push();
        fflush(stdin);
        printf("ADD ANOTHER NODE (Y/N)?: ");
        ch=getchar();
    }
    display();
}
void push()
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("ENTER NODE DATA: ");
    scanf("%d", &ptr->data);
    ptr->link=NULL;

    if(top==NULL)
    {
        top=ptr;
    }

    else
    {
        ptr->link=top;
        top=ptr;
    }
    printf("ELEMENT SUCCESSFULLY INSERTED\n");
}

void display()
{
    struct node *ptr; // for traversing purposes
    ptr=top;

    if(ptr==NULL)
    {
        printf("NO NODES IN THE STACK\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d--> ", ptr->data);
            ptr=ptr->link;
        }
    }

}
