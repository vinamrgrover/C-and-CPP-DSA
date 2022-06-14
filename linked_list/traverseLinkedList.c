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
		new_node -> next = NULL; 

		if(!(*head))
		{
				*head = new_node; 
				return; 
		}

		new_node -> next = *head; 
		*head = new_node; 

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

		printList(head); 

		return 0; 
}

