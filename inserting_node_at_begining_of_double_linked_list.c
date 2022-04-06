#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void display();
void add_at_beg();
int length();
struct node *root;
int main()
{
    root=(struct node*)malloc(sizeof(struct node));
    printf("NODE 1 DATA: ");
    scanf("%d", &root->data);
    root->left=NULL;
    root->right=NULL;

    struct node *current;
    current=(struct node*)malloc(sizeof(struct node));
    printf("NODE 2 DATA: ");
    scanf("%d", &current->data);
    current->right=NULL;
    root->right=current; // so that the first node starts pointing towards the second node
    current->left=root; // so that the second node starts pointing towards the first node

    current=malloc(sizeof(struct node));
    printf("NODE 3 DATA: ");
    scanf("%d", &current->data);
    current->right=NULL;
    current->left=root->right; // so that the third node starts pointing towards the second node
    root->right->right=current; // so that the second node starts pointing towards the third node

    display();
    add_at_beg();
    printf("NODE ADDED AT THE BEGINNING\n");
    display();
    int len=length();
    printf("\nLENGTH OF THE LINKED LIST: %d", len);

}

void add_at_beg()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nENTER TEMP NODE DATA: ");
    scanf("%d", &temp->data);
    temp->left=NULL;
    temp->right=NULL;

    if(root==NULL)
    {
        root=temp;
    }

    else
    {
        temp->right=root; // storing the base address of the first node into the right part of the temp node
        root->left=temp; // storing the base address of the temp node into the left part of the first node
        root=temp; // so that the root pointer starts pointing to the newly added first node of the linked list
    }
}

void display()
{
    struct node *ptr; // for traversing purposes

    ptr=root; // so that ptr becomes capable of pointing towards the first node of the linked list

    while(ptr!=NULL)
    {
        printf("%d--> ", ptr->data);
        ptr=ptr->right;
    }
}

int length()
{
    struct node *ptr;   // for traversing purposes
    ptr=root;
    int length=0;

    while(ptr!=NULL)
    {
        length++;
        ptr=ptr->right;
    }

    return length;
}