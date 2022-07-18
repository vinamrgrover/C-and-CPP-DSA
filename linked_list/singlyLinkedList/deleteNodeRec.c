#include<stdio.h>
#include<stdlib.h> 
struct node
{
		int data; 
		struct node *next; 
}; 

void insertNode(struct node **head, int data)
{
		struct node *new_node = (struct node *)malloc(sizeof(struct node)); 
		new_node -> data = data; 
		
		if(*head == NULL)
		{
				*head = new_node; 
				new_node -> next = NULL;
				return; 
		}

		new_node -> next  = *head; 
		*head = new_node; 
}

struct node *deleteNode(struct node *start, int i)
{
		if(i<1)
				return start;
							
		if(start == NULL)
				return NULL;

		if(i == 1)
		{
				struct node *res = start -> next; 
				free(start);
				return res; 
		}
													
		start -> next = deleteNode(start -> next, i-1); 
		return start; 
}


void printList(struct node *Node)
{
		while(Node != NULL)
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


		head = deleteNode(head, 1); 
		head = deleteNode(head, 2);  
		printList(head); 

		return 0; 
}

		
