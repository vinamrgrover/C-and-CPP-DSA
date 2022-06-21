#include<stdio.h> 
void insertionSort(int *arr, int len)
{
		for(int i=1; i<len; ++i)
		{						
				int key = arr[i]; 
				int j = i - 1; 
														
				while(key < arr[j] && j >= 0)
				{
						arr[j + 1] = arr[j]; 
						--j; 
				}
										
				arr[++j] = key; 
		}

}

int main()
{
		int arr[] = {5, 12, 1, 4, 3, 56, 34}; 
		int len = *(&arr + 1) - arr; 
					
		insertionSort(arr, len); 

		for(int i=0; i<len; ++i)
				printf("arr[%d] = %d\n", i, arr[i]); 

		return 0; 
}

