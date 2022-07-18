#include<iostream> 
using namespace std; 
class node
{
public:
		int data; 
		node *next; 
}; 
																																	
node *util = NULL; // utility pointer for constant insertion time

void appendNode(node **head, int data)
{
		node *new_node = new node; 

		new_node -> data = data; 

		node *temp = *head;
		
		if(!(*head)) // if the list is empty
		{							
				*head = util = new_node; 
																				
				new_node -> next = *head; 

				return; 
		}

		util -> next = new_node; // appending node

		util = new_node; // updating util 

		new_node -> next = *head; // updating new_node -> next
}

void printList(node *Node)
{
		if(!Node)  // underflow
				return; 
						
		node *temp = Node; 
		cout << Node -> data << " ";
		Node = Node -> next; 
									
		while(Node != temp) 
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
																
		printList(head); // (10 -> 20 -> 30 -> 40)

		return 0; 
}

