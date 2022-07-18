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
		
		if(!(*head))
		{
				*head = util = new_node; 

				new_node -> next = *head; 

				return; 
		}

		util -> next = new_node; 

		new_node -> next = *head; 

		util = new_node; 
}

void deleteNode(node **head, int key)
{
		if(!(*head))
				return;
																												
		if((*head) -> data == key) // first node
		{														
				node *temp = *head;
				while(temp -> next != *head) // traversing till the last node
						temp = temp -> next;
											
				*head = (*head) -> next; // updating head
				temp -> next = *head; // updating temp -> next
				return; 
		}

		node *temp = *head, *prev = *head; 

		while(temp -> data != key) 
		{
				prev = temp;			
				temp = temp -> next; 
		}

		if(temp -> next == *head) // last node
		{
				prev -> next = *head; // updating prev -> next
				free(temp); 
				return; 
		}
											
		prev -> next = temp -> next; // other cases
		free(temp); 
}
void printList(node *Node)
{
		if(!Node)
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
		appendNode(&head, 50); 

		printList(head); //(10 -> 20 -> 30 -> 40 -> 50)
								
		deleteNode(&head, 50); 
		deleteNode(&head, 10); 

		printList(head); // (20 -> 30 -> 40)

		return 0;
}

