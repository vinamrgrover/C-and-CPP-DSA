#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int length();
void reverse_list();
void display();
struct node *root;
int main()
{
    root=(struct node*)malloc(sizeof(struct node));
    printf("NODE 1: ");
    scanf("%d", &root->data);
    root->link=NULL;

    struct node *current;
    current=(struct node*)malloc(sizeof(struct node));
    printf("NODE 2: ");
    scanf("%d", &current->data);
    current->link=NULL;
    root->link=current; // storing the base address of the second node into the base address of the link part of the first node


     current=malloc(sizeof(struct node));
     printf("NODE 3: ");
     scanf("%d", &current->data);
     current->link=NULL;
     root->link->link=current; //storing the base address of the third node into the link part of the second node

     printf("BEFORE REVERSING\n");
     display();
     printf("\nAFTER REVERSING\n");
     reverse_list();
     display();

}

void reverse_list()
{
    struct node *p, *q; // p is for traversing from the beginning of the linked list and q is for traversing from the end of the linked list
    int i, j, k, len;
    p=q=root;
    len=length();
    i=0;
    j=len-1;

    while(i<j)
    {
        k=0;

        while(k<j)
        {
            q=q->link;     // moving q to the end of the linked list
            k++;
        }

        int temp=p->data;
        p->data=q->data;
        q->data=temp;

        i++;
        j--;
        p=p->link;
        q=root;  // moving q to the beginning of the linked list so that we can move the q again to the end of the linked list
    }

}

int length()
{
    struct node *ptr;
    ptr=root;
    int length=0;

    while(ptr!=NULL)
    {
        length++;
        ptr=ptr->link;
    }

    return length;
}

void display()
{
    struct node *ptr;
    ptr=root;

    while(ptr!=NULL)
    {
        printf("%d--> ", ptr->data);
        ptr=ptr->link;
    }
}