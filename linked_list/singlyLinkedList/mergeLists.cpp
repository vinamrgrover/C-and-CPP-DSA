#include<iostream> 
#include<stdbool.h>
#include<assert.h> 
using namespace std; 
class node
{
		public:
		int data; 
		node *next;
}; 

void shiftNode(node **resNode, node **srcNode)
{
		node *new_node = *srcNode; 
								
		if(!new_node)
				return; 
											
		(*srcNode) = new_node -> next; 

		new_node -> next = *resNode; 

		*resNode = new_node;

}

node *mergeList(node *listOne, node *listTwo)
{
		assert(listOne && listTwo); 
						
		node dummy; 

		node *tail = &dummy;

		dummy.next = NULL; 

		while(true)
		{
				if(listOne == NULL)
				{
						tail -> next = listTwo; 
						break; 
				}

				else if(listTwo == NULL)
				{
						tail -> next = listOne; 
						break; 
				}
																
				if(listOne -> data <= listTwo -> data)
						shiftNode(&(tail -> next), &listOne); 

				else
						shiftNode(&(tail -> next), &listTwo); 

				tail = tail -> next; 
		}

		return (dummy.next);
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
		if(!Node)
				return; 

		while(Node)
		{
				cout << Node -> data << " "; 
				Node = Node -> next; 
		}

		cout << endl;
}

int main()
{
		node *listOne = NULL; 
									
		insertNode(&listOne, 30); 
		insertNode(&listOne, 25); 
		insertNode(&listOne, 10);
		//listOne => (10 -> 25 -> 30)

			
		node *listTwo = NULL; 
		
		insertNode(&listTwo, 50); 
		insertNode(&listTwo, 40); 
		insertNode(&listTwo, 20); 
		//listTwo => (20 -> 40 -> 50)

		node *resList = NULL; 
													
		resList = mergeList(listOne, listTwo); 
		//resList(10 -> 20 -> 25 -> 30 -> 40 -> 50)
		printList(resList); 

		return 0;
}

