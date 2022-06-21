#include<stdio.h>
void bubbleSort(int *arr, int len)
{
		for(int i=0; i<len; ++i)
		{
				for(int j=0; j<len-i-1; ++j)
				{
						if(arr[j] > arr[j+1])
						{
								int temp = arr[j]; 
								arr[j] = arr[j+1]; 
								arr[j+1] = temp; 
						}
				}
		}
}

int main()
{
		int arr[] = {4, 23, 1, 56, 2, 3, 11, 21}; 

		int len = *(&arr + 1) - arr; 

		bubbleSort(arr, len); 

		for(int i=0 ; i<len; ++i)
				printf("arr[%d] = %d\n", i, arr[i]); 

		return 0; 
}

