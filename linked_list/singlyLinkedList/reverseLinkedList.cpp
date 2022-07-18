#include<iostream>
using namespace std; 
class node
{
public:
		int data; 
		node *next; 
};
					
node *util = NULL; 
												
void appendNode(node **head, int data)
{
		node *new_node = new node; 
		new_node -> data = data; 
		new_node -> next = NULL; 
									
		if(!(*head))
		{
				*head = util = new_node; 
				return; 
		}
						
	
		util -> next = new_node; 
		util = new_node; 
}

void deleteNode(node **head, int key)
{
		if(!head)
				return; 

		else if((*head) -> data == key)
		{
				node *temp = *head;
				*head = (*head) -> next; 
				free(temp); 
				return;
		}
										
		node *current = *head, *prev = *head; 
											
		while(current -> data != key)
		{
				prev = current;				
				current = current -> next;
		}
												
		prev -> next = current -> next; 
		free(current); 
}

void reverseLinkedList(node **head)
{
		node *next = NULL, *prev = NULL, *current = *head; 

		while(current != NULL)
		{
				next = current -> next; //keeping a track of next node				
										
				current -> next = prev; //linking current node with the prev node
									
				prev = current; //updating prev

				current = next; //updating current
		}

		*head = prev; //changing the head
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
		appendNode(&head, 10); 
		appendNode(&head, 20); 
		appendNode(&head, 30); 
		appendNode(&head, 40); 
		appendNode(&head, 50); 
							
		printList(head); //before reversing

		reverseLinkedList(&head); 
							
		printList(head); //after reversing

		return 0; 
}

