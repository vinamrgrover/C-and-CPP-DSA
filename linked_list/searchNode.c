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

		if(*head == NULL)
				*head = new_node;

		else
		{
				new_node -> next = *head; 
				*head = new_node; 
		}

}
												
struct node *searchNode(struct node **head, int key)
{
		if((*head) -> data == key)
				return *head; 
		
		else if(*head == NULL)
				return NULL; 
		else
		{
				struct node *temp = *head; 

				while(temp -> data != key)
				{
						temp = temp -> next; 
						if(!temp)
								return NULL;   // returning NULL if a searched node is not found   
				}

				return temp; 
		}
						
}

int main()
{
		struct node *head = NULL; 
		insertNode(&head, 10); 
		insertNode(&head, 20); 
		insertNode(&head, 30); 

		struct node *new_node = searchNode(&head, 20);

		if(new_node)
				printf("%d\n", new_node -> data); 

		new_node = searchNode(&head, 100);

		if(new_node)							// failed because the node with the given key doesn't exist
				printf("%d\n", new_node -> data);  

		return 0; 
}

