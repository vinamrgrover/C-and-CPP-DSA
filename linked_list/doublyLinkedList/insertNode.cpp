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

		if(!(*head)) // if the list is empty
		{
				*head = new_node; 
																
				new_node -> next = new_node -> prev = NULL; 

				return; 
		}
																																								
		new_node -> next = *head;   // changing the next of the new_node
										 
		(*head) -> prev = new_node; // changing the prev of the head node
		
		*head = new_node; //changing the head
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

	insertNode(&head, 40); 
	insertNode(&head, 30); 
	insertNode(&head, 20); 
	insertNode(&head, 10); 

	printList(head); 

	return 0; 
}

