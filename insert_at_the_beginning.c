#include<stdio.h>
#include<stdlib.h>
void at_the_beg() ;
struct node
{
    int data;
    struct node *link;
};
struct node *root;
int main()
{
    root=(struct node*)malloc(sizeof(struct node));
    printf("enter data(node 1): ");
    scanf("%d", &root->data);
    root->link=NULL;

    struct node *current;
    current=(struct node*)malloc(sizeof(struct node));
    printf("enter data(node 2): ");
    scanf("%d", &current->data);
    current->link=NULL;
    root->link=current; //storing the base address of the second node into the link part of the first node

    current=malloc(sizeof(struct node)); //using the same pointer to create another node

    printf("enter data(node 3): ");
    scanf("%d", &current->data);
    current->link=NULL;

    root->link->link=current; // we are storing the base address of the third node into the link part of the second node

    at_the_beg();

}

void at_the_beg()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter node data: ");
    scanf("%d", &temp->data);
    temp->link=NULL;

    if(root==NULL)  // checking if temp is the first node to be inserted into the linked list
    {
        root=temp; // now root will point towards the newly created and the first node of the linked list
    }

    else
    {
        temp->link=root;  // this will store the base address of the previously first node into the link part of the temp node
        root=temp;   // this will store the base address of the temp node into the root, and now root will point towards the temp node
    }

    printf("node successfully inserted at the beginning of the linked list\n"); //node inserted at the beginning


    //printing the data of the nodes
    printf("printing the node data\n");
    printf("root 1: %d\n", root->data);
    printf("root 2: %d\n", root->link->data);
    printf("root 3: %d\n", root->link->link->data);
    printf("root 4: %d\n", root->link->link->data);


}