#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, pos, num;
    printf("SIZE: ");
    scanf("%d", &n);

    int *arr=(int*)calloc(n, sizeof(int));

    printf("ENTER THE ELEMENTS: \n");

    for(int i=0; i<n; i++)
    {
        printf("%d: ", i+1);
        scanf("%d", (arr+i));
    }
    printf("BEFORE INSERTION: \n");
    for(int i=0; i<n; i++)
    {
        printf("arr[%d] = %d\n",i, *(arr+i));
    }
    printf("ENTER THE ELEMENT YOU WANT TO INSERT: ");
    scanf("%d", &num);
    printf("ENTER THE POSITION: ");
    scanf("%d", &pos);

    //increasing the size of the array by 1
    arr=realloc(arr, (n+1)*sizeof(arr));

    for(int i=n-1; i>=pos; i--)
    {
        *(arr+i+1)=*(arr+i);
    }
    *(arr+pos)=num;


    printf("AFTER INSERTION: \n");

    for(int i=0; i<=n; i++)
    {
        printf("arr[%d] = %d\n", i, *(arr+i));
    }
}
