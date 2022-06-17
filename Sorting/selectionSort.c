#include<stdio.h> 
#include<stdlib.h> 
void selectionSort(int *arr, int len)
{
		for(int i = 0; i < len - 1; ++i)
		{
				int min = i; 

				for(int j = i + 1; j < len; ++j)
				{

						if(arr[j] < arr[min])
								min = j;

				}
		
				int temp = arr[i]; 
				arr[i] = arr[min]; 
				arr[min] = temp; 
		}

}

int main()
{
		int arr[] = {60, 3, 22, 1, 2, 5, 67, 12}; 

		int len = *(&arr + 1) - arr; 

		selectionSort(arr, len); 

		for(int i=0; i < len; ++i)
				printf("arr[%d] = %d\n", i, arr[i]); 

		return 0; 
}
						
							
