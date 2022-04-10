#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *link;
};
void append();
void add_at_beg();
void display();
int length();
void in_the_middle();
void delete();
struct node *root=NULL;
int main()
{
    int ch;
    while(true)
    {
        printf("\n1. APPEND(insert)\n");
        printf("2. INSERT IN THE BEGINNING\n");
        printf("3. LENGTH\n");
        printf("4. INSERT IN THE MIDDLE\n");
        printf("5. DISPLAY\n");
        printf("6. DELETE\n");
        printf("7. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
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
                add_at_beg();
                break;
            }
            case 3:
            {
               int len=length();
               printf("LENGTH OF THE LINKED LIST IS: %d\n", len);
               break;
            }

            case 4:
            {
                in_the_middle();
                break;
            }

            case 5:
            {
                display();
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
    temp->link=NULL;

    if(ptr==NULL)
    {
        root=temp;
        printf("NODE SUCCESSFULLY INSERTED INTO THE LINKED LIST\n");
    }

    else
    {
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;
        printf("NODE SUCCESSFULLY INSERTED INTO THE LINKED LIST\n");
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
}

void add_at_beg()
{
    struct node *temp, *ptr;
    ptr=root;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("ENTER NODE DATA: ");
    scanf("%d", &temp->data);
    temp->link=NULL;

    if(ptr==NULL)
    {
        root=temp;
    }

    else
    {
        temp->link=ptr;
        root=temp;
        printf("NODE SUCCESSFULLY INSERTED IN THE BEGINNING\n");
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

void in_the_middle()
{
    struct node *temp, *ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("ENTER THE NODE DATA: ");
    scanf("%d", &temp->data);
    temp->link=NULL;
    ptr=root;
    int pos, len;
    len=length();
    printf("ENTER THE POSITION: ");
    scanf("%d", &pos);

    if(pos>len)
    {
        printf("INVALID POSITION ENTERED\n");
        printf("THE LINKED LIST CONSISTS OF %d NODES\n", len);
    }

    else
    {
        int i=1;

        while(i<pos)
        {
            ptr=ptr->link;
            i++;
        }
        temp->link=ptr->link;
        ptr->link=temp;
        printf("THE NODE IS SUCCESSFULLY INSERTED IN THE MIDDLE\n");
    }

}

void delete()
{
    struct node *p, *q;
    p=root;
    int pos, len=length();
    printf("ENTER THE POSITION: ");
    scanf("%d", &pos);

    if(pos>len)
    {
        printf("INVALID POSITION ENTERED\n");
        printf("THE LINKED LIST CONSISTS OF %d NODES\n", len);
    }

    else
    {
        int i=1;

        while(i<pos-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        free(q); // freeing the dynamically allocated memory by the q node so that it can be reused in the future again
        printf("NODE SUCCESSFULLY DELETED FROM THE LINKED LIST\n");
    }
}
