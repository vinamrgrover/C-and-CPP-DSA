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

		if(!(*head))
		{
				*head = new_node; 
				return;
		}

				/*this approach takes O(n) time 
				 because of travesa, which is 
				 time costly */

				struct node *temp = *head; 

				while(temp -> next)
						temp = temp -> next;

				temp -> next = new_node; 

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
								
		appendNode(&head, 10); 
		appendNode(&head, 20); 
		appendNode(&head, 30); 

		printList(head); 

		return 0; 
}

