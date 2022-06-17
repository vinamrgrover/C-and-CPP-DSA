#include<stdio.h> 
#include<stdlib.h>	
void merge(int *arr, int *left, int lSize, int *right, int rSize)
{																		
		int i = 0, j = 0, k = 0; 
									
		while(i<lSize && j<rSize)
		{
				if(left[i] < right[j])			
						arr[k++] = left[i++];

				else
						arr[k++] = right[j++]; 
		}

		while(i<lSize)
				arr[k++] = left[i++]; 

		while(j<rSize)
				arr[k++] = right[j++]; 

}


void mergeSort(int *arr, int len)
{
		if(len < 2)
				return; 

		int mid = len / 2; 

		int *left = (int *)calloc(mid, sizeof(int)); 
		int *right = (int *)calloc(len - mid, sizeof(int)); 

		for(int i=0; i<mid; ++i)
				left[i] = arr[i]; 

		for(int i=mid; i<len; ++i)
				right[i - mid] = arr[i]; 
											
		mergeSort(left, mid); 
		mergeSort(right, len - mid); 
		merge(arr, left, mid, right, len - mid); 
		free(left); 
		free(right);
}

int main()
{
		int arr[] = {3, 4, 1, 10, 12, 2, 0, 11, 5}; 
												
		int len = *(&arr + 1) - arr; 
									
		mergeSort(arr, len);
								
		for(int i=0; i < len; ++i)
				printf("arr[%d] = %d\n", i, arr[i]);

		return 0; 
}

