#include<stdio.h> 
#include<stdlib.h> 
struct node
{
		int data; 
		struct node *next;
};							

struct node *temp = NULL; //global pointer temp 
						  //for keeping the reference of last node inserted 
void appendNodeConstTime(struct node **head, int data)
{
		struct node *new_node = (struct node *)malloc(sizeof(struct node)); 

		new_node -> data = data; 
		new_node -> next = NULL; 

		if(!(*head)) // if the list is empty (underflow)
		{
				*head = temp = new_node; 
				return; 
		}

		/*by using a reference pointer, appending
		 a node will take a constant time of O(1) */

		temp -> next = new_node; 
		temp = new_node; //updating temp

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
		appendNodeConstTime(&head, 10); 
		appendNodeConstTime(&head, 20); 
		appendNodeConstTime(&head, 30); 
		appendNodeConstTime(&head, 40); 

		printList(head); 

		return 0; 
}


				
			
