#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int main()
{
    struct node *root;

    root=(struct node*)malloc(sizeof(struct node));
    printf("DATA(NODE 1):");
    scanf("%d", &root->data);
    root->link=NULL;


    struct node *current;
    current=(struct node*)malloc(sizeof(struct node)); //typecasting because malloc returns a void pointer (Typecasting is not necessary)

    printf("DATA(NODE 2):");
    scanf("%d", &current->data);
    current->link=NULL;
    root->link=current;

    current=malloc(sizeof(struct node));  //we can use the same pointer for declaring another node

    printf("DATA(NODE 3):");
    scanf("%d", &current->data);
    current->link=NULL;
    root->link->link=current; //now the base address of the third node will be stored into the link part(pointer)of the second node


    printf("%d\n", root->data);
    printf("%d\n", root->link->data);
    printf("%d\n", root->link->link->data);


}