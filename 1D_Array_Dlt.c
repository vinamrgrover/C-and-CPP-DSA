#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, pos;
    printf("SIZE: ");
    scanf("%d", &n);

    int *arr=(int*)calloc(n, sizeof(int));
    printf("ENTER THE ELEMENTS: \n");

    for(int i=0; i<n; i++)
    {
        printf("%d: ", i+1);
        scanf("%d", (arr+i));
    }

    printf("BEFORE DELETING\n");

    for(int i=0; i<n; i++)
    {
        printf("arr[%d] = %d\n", i, *(arr+i));
    }

    printf("ENTER THE POSITION: ");
    scanf("%d", &pos);

    for(int i=pos; i<n-1; i++)
    {
        *(arr+i)=*(arr+i+1);
    }

    /*for reducing the size of the array by 1 */
    arr=realloc(arr, (n-1)*sizeof(int));

    printf("AFTER DELETING: \n");

    for(int i=0; i<n-1; i++)
    {
        printf("arr[%d] = %d\n", i, *(arr+i));
    }
}
