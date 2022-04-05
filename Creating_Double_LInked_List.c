#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *right; // to point towards the next node
    struct node *left; // to point towards the previous node
};
struct node *root;
void display();
void append();
int main()
{
    root=(struct node*)malloc(sizeof(struct node));
    printf("NODE 1 DATA: ");
    scanf("%d",  &root->data);
    root->left=NULL;
    root->right=NULL;

    struct node *current;
    current=(struct node*)malloc(sizeof(struct node));
    printf("NODE 2 DATA: ");
    scanf("%d", &current->data);
    current->right=NULL;
    current->left=root; // so that the second node starts pointing towards the first node
    root->right=current; // so that the first node starts pointing towards the second node

    current=malloc(sizeof(struct node));
    printf("NODE 3 DATA: ");
    scanf("%d", &current->data);
    current->right=NULL;
    current->left=root->right;
    root->right->right=current;

    display();
    append();
    display();


}

void display()
{
    struct node *ptr;

    ptr=root;

    while(ptr!=NULL)
    {
        printf("%d--> ", ptr->data);
        ptr=ptr->right;
    }
}

void append()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nENTER NODE DATA: ");
    scanf("%d", &temp->data);
    temp->left=NULL;
    temp->right=NULL;

    if(root==NULL)
    {
        root=temp; // so that root starts pointing towards the temp node
    }

    else
    {
        struct node *ptr; // for traversing purposes
        ptr=root; // so that ptr starts pointing towards the first node of the linked list


        while(ptr->right!=NULL)  // so that the ptr traverses from the beginning to the end node of the linked list
        {
            ptr=ptr->right;
        }

        temp->left=ptr; // storing the base address of the third node into the left part of the temp node
        ptr->right=temp; // storing the base address of the temp node into the right part of the third node

    }

}