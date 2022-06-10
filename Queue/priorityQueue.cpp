#include<iostream>
#include<limits.h>
#define MAX_SIZE 20
using namespace std;
struct Elmt
{
		int value;
		int priority;
};
struct Elmt pQueue[MAX_SIZE];
int size = -1;
void enqueue(int value, int priority)
{
		++size;
		pQueue[size].value = value;
		pQueue[size].priority = priority;
}

int peek()
{
		int maxPriority = INT_MIN;
		int index = -1;

		for(int i=0; i<size; ++i)
		{
				if(pQueue[index].priority == pQueue[i].priority
                && pQueue[index].value < pQueue[i].value)
				{
						maxPriority = pQueue[i].priority;
						index = i;
				}

				else if(maxPriority < pQueue[i].priority)
				{
						maxPriority = pQueue[i].priority;
						index = i;
				}

		}

		return index;
}

void dequeue()
{
		int index = peek();

		for(int i=index; i<size; ++i)
				pQueue[i] = pQueue[i+1];

		--size;
}

int main()
{
		//enqueue
		enqueue(1, 2);
		enqueue(2, 50);
		enqueue(3, 2);
		enqueue(4, 1);

		// element with the highgest priority
		cout << pQueue[peek()].value << endl;

		dequeue(); // dequeue the element with the highest priority

		cout << pQueue[peek()].value << endl;

		return 0;

}

