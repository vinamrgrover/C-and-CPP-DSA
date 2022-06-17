#include<iostream> 
using namespace std;
struct node
{
		int data; 
		struct node *next; 
};

node *findMiddleElement(node *head)
{
		if(head)
		{
				node *slow = head, *fast = head;
				
				while(fast && fast -> next)
				{
						slow = slow -> next; 
						fast = fast -> next -> next; 
				}

				return slow;
		}
						
		return NULL; // if the linked list is empty
}
					
void insertNode(node **head, int data)
{
		node *new_node = new node; 
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
		insertNode(&head, 10); 
		insertNode(&head, 20); 
		insertNode(&head, 30); 
		insertNode(&head, 40); 
		insertNode(&head, 50); 

		printList(head); 

		node *temp = findMiddleElement(head); // finding middle element
																										
		if(temp)
				cout << temp -> data << endl; 

		return 0; 
}

