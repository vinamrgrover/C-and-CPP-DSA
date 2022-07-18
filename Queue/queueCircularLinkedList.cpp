#include<iostream> 
using namespace std;

class node
{
public:
		int data; 
		node *next;
}; 

node *front = NULL; 
node *rear = NULL; 
										
void enQueue(int data)
{
		node *new_node = new node; 
		new_node -> data = data; 
																			
		if(!front && !rear)			
		{								
				front = rear = new_node;
				new_node -> next = front; 
				return; 
		}
								
		rear -> next = new_node;
		new_node -> next = front; 
		rear = new_node; 
}

void deQueue()
{
		if(!front && !rear)
				return; 

		else if(rear == front)
		{
				rear = front = NULL; 
				return; 
		}

		node *temp = front;		
									
		front = front -> next; // updating front 
														
		rear -> next = front; // updating (rear -> next)
							  
		free(temp); // free temp node
}

void traverseQueue()
{
		if(!rear && !front)
				return; 

		node *Node = front;

		cout << Node -> data << " "; 
		Node = Node -> next;

		while(Node != front)
		{
				cout << Node -> data << " "; 
				Node = Node -> next; 
		}

		cout << endl; 
}

node *getFront()
{
		return front; 
}

node *getRear()
{
		return rear; 
}

int main()
{
		enQueue(10); 
		enQueue(20); 
		enQueue(30); 
		enQueue(40); 
		enQueue(50); 

		traverseQueue(); 
												
		deQueue(); 
		deQueue(); 

		traverseQueue(); 
											
		node *front_node = getFront(); // node at front
		
		node *rear_node = getRear();  // node at rear
																													
		if(front_node) 
				cout << front_node -> data << endl; 
														
		if(rear_node) 
				cout << rear_node -> data << endl; 
	
		return 0; 
}

