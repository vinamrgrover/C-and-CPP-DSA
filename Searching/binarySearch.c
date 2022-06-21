#include<stdio.h>
int binarySearch(int *arr, int len, int num)
{									
		int lb = 0, ub = len - 1, mid = ( (lb + ub) / 2 );
																													
		while(lb <= ub)
		{
				if(arr[mid] == num)
						return mid; 


				else if(num > arr[mid])
				{
						lb = mid + 1; 
						mid = (lb + ub) / 2; 
				}

				else
				{
						ub = mid - 1; 
						mid = (lb + ub) / 2; 
				}

		}

		return 0; 
}

int main()
{
		int arr[] = {12, 31, 45, 56, 78, 98, 102}; 
		int len = *(&arr + 1) - arr;
																								
		int index = binarySearch(arr, len, 98); 

		if(index)
				printf("%d\n", arr[index]); 
}

