#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next; 
};

void appendNode(struct node **head, int data)
{
		struct node *new_node = (struct node *)malloc(sizeof(struct node)); 
		new_node -> data = data; 
		new_node -> next = NULL; 

		struct node *temp = *head;

		while(temp -> next)
				temp = temp -> next; 

		temp -> next = new_node; 
}

void insertNode(struct node **head, int data)
{
		struct node *new_node = (struct node *)malloc(sizeof(struct node)); 
		new_node -> data = data; 
		new_node -> next = NULL; 

		new_node -> next = *head; 
		*head = new_node; 
}

void deleteNode(struct node **head, int key)
{
		struct node *temp = *head, *prev; 
		if(temp != NULL && temp -> data ==key)
		{
				*head=temp -> next;  
				free(temp);
				return; 
		}
										
		while(temp -> data != key)
		{
				if(temp == NULL)
						return; 
				prev = temp; 
				temp = temp -> next; 
		}


		prev -> next = temp -> next;

		free(temp); 

}

void printList(struct node *Node)
{
	while(Node)
	{									
			printf("%d ", Node -> data); 
			Node = Node -> next; 
	}

	printf("\n"); 
}


int main()
{
		struct node *head = NULL; 
		insertNode(&head, 10); 
		insertNode(&head, 20); 
		insertNode(&head, 30);
		insertNode(&head, 40); 
		deleteNode(&head, 20);
		deleteNode(&head, 40); 
		printList(head); 

		return 0; 

} 

