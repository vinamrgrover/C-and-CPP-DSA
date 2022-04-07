#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void in_the_middle();
int length();
void display();
struct node *root;
int main()
{
    root=(struct node*)malloc(sizeof(struct node));
    printf("NODE 1: ");
    scanf("%d", &root->data);
    root->left=NULL;
    root->right=NULL;

    struct node *current;
    current=(struct node*)malloc(sizeof(struct node));
    printf("NODE 2: ");
    scanf("%d", &current->data);
    current->left=root; // storing the base address of the first node into the left part of the second node
    current->right=NULL;
    root->right=current; // storing the base address of the second node into the right part of the first node

    current=malloc(sizeof(struct node));
    printf("NODE 3: ");
    scanf("%d", &current->data);
    current->right=NULL;
    current->left=root->right; // storing the base address of the second node into the left part of the third node
    root->right->right=current; // storing the base address of the third node into the right part of the second node

    current=malloc(sizeof(struct node));
    printf("NODE 4: ");
    scanf("%d", &current->data);
    current->right=NULL;
    current->left=root->right->right;// storing the base address of the third node into the left part of the fourth node
    root->right->right->right=current; // storing the base address of the fourth node into the right part of the third node

    printf("DISPLAYING ALL THE NODES\n");
    display();
    printf("\nINSERTING NODE IN THE MIDDLE\n");
    in_the_middle();
    printf("DISPLAYING ALL THE NODES\n");
    display();

}

void in_the_middle()
{
   struct node *temp, *ptr; // ptr for traversing purposes
   int i=1, pos, len;
   ptr=root; // so that ptr becomes capable of pointing towards the first node of the linked list
   len=length();
   printf("ENTER THE POSITION: ");
   scanf("%d", &pos);

   if(pos>len)
   {
       printf("INVALID POSITION ENTERED\n");
       printf("THE LINKED LIST HAS %d NODES", len);
   }

   else
   {
       temp=(struct node*)malloc(sizeof(struct node));
       printf("ENTER TEMP NODE DATA: ");
       scanf("%d", &temp->data);
       temp->left=NULL;
       temp->right=NULL;

       while(i<pos)
       {
           ptr=ptr->right; // so that the ptr pointer reaches the desired destination in which the node is to be inserted
           i++;
       }

       temp->right=ptr->right; // storing the base address of the next node into the right part of the temp node
       ptr->right->left=temp; // storing the base address of the temp node into the left part of the next node
       temp->left=ptr; //storing the base address of the previous node into the left part of the temp node
       ptr->right=temp; // storing the base address of the temp node into the right part of the previous node
   }

}

int length()
{
    struct node *ptr;
    int length=0;

    ptr=root;

    while(ptr!=NULL)
    {
        length++;
        ptr=ptr->right;
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
        ptr=ptr->right;
    }
}