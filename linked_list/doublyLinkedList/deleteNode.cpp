#include<iostream>
using namespace std; 
class node
{
public:						
		int data; 
		node *next; 
		node *prev; 
}; 
										
void insertNode(node **head, int data)
{
		node *new_node = new node; 

		new_node -> data = data; 

		if(!(*head))
		{
				new_node -> prev = new_node -> next = NULL; 
				*head = new_node; 
				return; 
		}
									
		new_node -> next = *head; 

		(*head) -> prev = new_node; 

		*head = new_node; 
}

void deleteNode(node **head, int key)
{
		if(!(*head))
				return; 
																						
		else if((*head) -> data == key) // for the first node
		{
				node *temp = *head;
											
				(*head) = (*head) -> next; 
							
				free(temp); 

				return; 
		}

		node *temp = *head; 

		while(temp -> data != key)
				temp = temp -> next; 
														
		if(!(temp -> next)) // for the last node
		{																											
				temp -> prev -> next = NULL; 
				
				free(temp); 

				return; 
		}

		temp -> prev -> next = temp -> next; 

		temp -> next -> prev = temp -> prev; 

		free(temp);

}

void printList(node *Node)
{
		while(Node)
		{
				cout << Node -> data << " "; 
				Node = Node -> next; 
		}

		cout << endl; 
}

int main()
{
		node *head = NULL; 

		insertNode(&head, 50); 
		insertNode(&head, 40); 
		insertNode(&head, 30); 
		insertNode(&head, 20); 
		insertNode(&head, 10); 
							
		printList(head);  // before (10 -> 20 -> 30 -> 40 -> 50)
																			
		deleteNode(&head, 30); 
		deleteNode(&head, 10); 
		deleteNode(&head, 50); 

		printList(head); // after (20 -> 40)

		return 0; 
}

