#include<stdio.h>
#include<stdbool.h> 
#define MAX_SIZE 5
int rear = -1, front = -1;
int Queue[MAX_SIZE]; 
bool isFull()
{																				
		return ((rear == MAX_SIZE - 1 && front == 0) || front == rear + 1 );
}
bool isEmpty()
{
		return rear == -1 && front == -1;  
}
							
void insertRear(int n)
{
		if(isFull())
				return;
									
		else if(isEmpty())
				rear = front = 0; 

		else if(rear == n-1)
				rear = 0;
							
		else
				++rear; 
						
		Queue[rear] = n;
}

void insertFront(int n)
{
		if(isFull())
				return;

		if(isEmpty())
				rear = front = 0; 

		if(front == 0)
				front = MAX_SIZE -1; 

		else
				--front;

		Queue[front] = n; 
}

void deleteFront()
{
		if(isEmpty())
				return;
										
		if(rear == front)
				rear = front = - 1; 

		if(front == MAX_SIZE - 1)
				front = 0;

		else
				++front; 
}

void deleteRear()
{
		if(isEmpty())
				return; 

		if(rear == front)
				rear = front = -1; 

		if(rear == 0)
				rear = MAX_SIZE - 1; 

		else 
				--rear;
}

void printQueue()
{
		if(isEmpty())
				return; 

		if(rear >= front)
		{
				for(int i=front; i<=rear; ++i)
						printf("%d ", Queue[i]);
		}

		else
		{
				for(int i=0; i<=rear; ++i)
						printf("%d ", Queue[i]); 

				for(int i=MAX_SIZE - 1; i>=front; --i)
						printf("%d ", Queue[i]); 
		}

	printf("\n"); 
}

int main()
{
		insertRear(10); 
		insertRear(20); 
		insertRear(30); 
		deleteRear();

		insertFront(40);
		insertFront(50); 
		deleteFront(); 

		printQueue(); 

		return 0; 
}


