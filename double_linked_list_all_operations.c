#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
void append();
void add_in_beginning();
void display();
int length();
void in_the_middle();
void delete();
struct node *root;
int main()
{
    int ch;
    while(true)
    {
        printf("\n1. APPENDING A NODE(insert): \n");
        printf("2. INSERTING NODE AT THE BEGINNING: \n");
        printf("3. DISPLAYING ALL THE NODES\n");
        printf("4. LENGTH OF THE DOUBLE LINKED LIST\n");
        printf("5. INSERTING NODE IN THE MIDDLE\n");
        printf("6. DELETING A NODE\n");
        printf("7. EXIT\n");
        printf("ENTER THE CHOICE: ");
        scanf("%d", &ch);


        switch(ch)
        {
            case 1:
            {
                append();
                break;
            }

            case 2:
            {
                add_in_beginning();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                int len=length();
                printf("THE LENGTH OF THE LINKED LIST IS: %d\n", len);
                break;
            }

            case 5:
            {
                in_the_middle();
                break;
            }
            case 6:
            {
                delete();
                break;
            }
            case 7:
            {
                exit(0);
            }
        }
    }
}

void append()
{
    struct node *temp, *ptr;
    ptr=root;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("ENTER NODE DATA: ");
    scanf("%d", &temp->data);
    temp->left=NULL;
    temp->right=NULL;

    if(ptr==NULL)
    {
        root=temp; // so that the root starts pointing towards the temp node
    }

    else
    {
        while(ptr->right!=NULL)
        {
            ptr=ptr->right;
        }

        temp->left=ptr;
        ptr->right=temp;
    }

}

void add_in_beginning()
{
    struct node *temp, *ptr;
    ptr=root;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("ENTER NODE DATA: ");
    scanf("%d", &temp->data);
    temp->left=NULL;
    temp->right=NULL;

    if(ptr==NULL)
    {
        root=temp;
    }

    else
    {
        temp->right=ptr; // storing the base address of the first node into the right part of the temp node
        ptr->left=temp; // storing the base address of the temp node into the left part of the first node
        root=temp;
        printf("SUCCESSFULLY INSERTED THE NODE IN THE BEGINNING\n");
    }

}

void display()
{
    struct node *ptr;
    ptr=root;

    if(ptr==NULL)
    {
        printf("THERE ARE NO NODES IN THE LINKED LIST\n");
    }

    else
    {
        printf("PRINTING THE DATA OF ALL THE NODES\n");
        while(ptr!=NULL)
        {
            printf("%d--> ", ptr->data);
            ptr=ptr->right;
        }
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
        ptr=ptr->right;
    }

    return length;
}

void in_the_middle()
{
    struct node *temp, *ptr;
    ptr=root;
    int i=1, pos, len;
    len=length();

    printf("ENTER THE POSITION: ");
    scanf("%d", &pos);

    if(pos>len)
    {
        printf("INVALID POSITION ENTERED\n");
        printf("THE LINKED LIST CONSISTS OF %d ELEMENTS\n", len);
    }

    else
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("ENTER NODE DATA: ");
        scanf("%d", &temp->data);
        temp->left=NULL;
        temp->right=NULL;

        while(i<pos)
        {
            ptr=ptr->right;
            i++;
        }

        temp->right=ptr->right; // so that the temp node starts pointing towards the next node
        ptr->right->left=temp;
        temp->left=ptr;
        ptr->right=temp;
        printf("NODE SUCCESSFULLY INSERTED AT THE POSITION: %d\n", pos);
    }

}

void delete()
{
    struct node *ptr;
    ptr=root;
    int pos, i=1;


    if(ptr==NULL)
    {
        printf("NO NODES IN THE LINKED LIST\n");
    }

    else
    {
        printf("ENTER THE POSITION OF THE NODE TO DELETE: ");
        scanf("%d", &pos);
        while(i<pos)
        {
            ptr=ptr->right;
            i++;
        }
        ptr->right->left=ptr->left; // storing the base address of the node before the ptr node into the left part of the node after ptr
        ptr->left->right=ptr->right; // storing the base address of the node after ptr into the right part of the node before ptr
        free(ptr); // freeing the dynamically allocated memory of the ptr node so that it can be reused in the future again
        printf("NODE SUCCESSFULLY DELETED\n");
    }
}
