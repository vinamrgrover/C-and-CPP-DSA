#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void insert();
int length();
void display();
void delete();
struct node *root;
int main()
{
    root=(struct node*)malloc(sizeof(struct node));
    printf("enter the node 1 data: ");
    scanf("%d", &root->data);
    root->link=NULL;

    struct node *current;
    current=(struct node*)malloc(sizeof(struct node));
    printf("enter the node 2 data: ");
    scanf("%d", &current->data);

    current->link=NULL;

    root->link=current; //storing the base address of the second node into the link part of the first node

    current=malloc(sizeof(struct node));
    printf("enter the node 3 data: ");
    scanf("%d", &current->data);
    current->link=NULL;

    root->link->link=current; //storing the base address of the third node into the link part of the second node

    insert();
    display();
    delete();
    display();

}

int length()
{
    struct node *ptr;   // for traversing thorough the linked list
    int count=0;

    ptr=root;    // ptr would now, be capable of pointing towards the first node of the linked list

    while(ptr->link!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    return count;
}

void insert()
{
    printf("inserting a node:\n");
    struct node *temp, *ptr;
    int pos, len;
    len=length();
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the temp node data: ");
    scanf("%d", &temp->data);
    temp->link=NULL;

    printf("enter the position in which you want to insert the node"); // on the basis of index number
    scanf("%d", &pos);

    if(pos>len)
    {
        printf("please enter the correct position\n");
        printf("the current length of the linked list is: %d", len);
    }

    else
    {
        ptr=root;
        int i=1;

        while(i<pos)
        {
            ptr=ptr->link;
            i++;
        }
        temp->link=ptr->link;
        ptr->link=temp; //storing the base address of the temp node into the previous node
    }
}

void display()
{
    struct node *ptr;
    ptr=root;

    while(ptr!=NULL)
    {
        printf("%d-->", ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}

void delete()
{

    printf("deleting the node: \n");
    struct node *temp;
    int pos, len;
    printf("enter the position of the node to delete");
    scanf("%d", &pos);
    len=length();

    if(pos>len)
    {
        printf("incorrect position entered\n");
        printf("the length of the linked list is: %d\n", len);
    }


    else if(pos==1)  // if the user wants to delete the first node of the linked list
    {
        temp=root;

        root=temp->link;   // now the root will point towards the second node of the linked list
        temp->link=NULL;    //so that the first node stops pointing towards the second node

        free(temp); //this will release the dynamically allocated memory occupied by the temp
    }


    else
    {
        struct node *p, *q;
        p=root;
        int i=1;

        while(i<pos-1) // because we want to delete that particular node. in the node insertion we have not given the '-1' because we want to insert after that specified location
        {
            p=p->link;
            i++;
        }
        q=p->link; // so that q starts pointing towards the node specified after that location
        p->link=q->link; // so that the node starts pointing towards the node after that node(to be deleted)
        q->link=NULL; //storing the NULL value into the link part of the node to be deleted(q)

        free(q); //freeing the dynamically allocated memory allocated to the q pointer


    }


}