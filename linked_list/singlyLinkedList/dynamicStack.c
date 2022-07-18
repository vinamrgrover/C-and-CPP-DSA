#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
		int data; 
		struct node *next; 
}; 

struct node *top = NULL;	// global pointer (top) 
							
bool isEmpty()
{
		return top == NULL; 
}

void push(int data)
{
		struct node *new_node = (struct node *)malloc(sizeof(struct node)); 
		new_node -> data = data; 
									
		if(isEmpty())	// when stack is empty
		{
				top = new_node; 
				top -> next = NULL;
				return; 
		}

		new_node -> next = top; 
		top = new_node;		//updating top
}
						

void pop()
{
		if(isEmpty())	//underflow
				return; 
									
		struct node *temp = top; 
		top = top -> next;		//updating top
		free(temp); 
}

void traverse()
{
		if(isEmpty())
				return; 

		struct node *temp = top; 
					
		while(temp)
		{
				printf("%d\n", temp -> data); 
				temp = temp -> next; 
		}
}

struct node *peek()
{
		return top; 
}

int main()
{
		push(10); // push operation
		push(20); 
		push(30); 
		push(40); 
		push(50); 
																						
		struct node *topNode = peek(); // peek operation

		if(topNode)								
				printf("%d\n", topNode -> data);  

		pop(); // pop operation
		pop(); 

		traverse(); 

		return 0; 
}

