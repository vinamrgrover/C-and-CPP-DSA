#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n, m;
    printf("SIZE(1): ");
    scanf("%d", &n);
    int *arr=(int*)calloc(n, sizeof(int));

    printf("ENTER THE ELEMENTS(1): \n");

    for(int i=0; i<n; i++)
    {
        printf("%d: ", i+1);
        scanf("%d", (arr+i));
    }

    printf("SIZE(2): ");
    scanf("%d", &m);

    int *new=(int*)calloc(n, sizeof(int));

    printf("ENTER THE ELEMENTS(2): \n");

    for(int i=0; i<m; i++)
    {
        printf("%d: ", i+1);
        scanf("%d", (new+i));
    }

    arr=realloc(arr, (m+n)*sizeof(int));
    /*increasing the size of the array
     * by the size of the second array  */

    for(int i=0; i<m; i++)
    {
        *(arr+n+i)=*(new+i);
    }

    printf("PRINTING THE ARRAY: \n");

    for(int i=0; i<(m+n); i++)
    {
        printf("arr[%d] = %d\n", i, *(arr+i));
    }
}
