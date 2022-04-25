#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int *insert(int *, int);
void traverse(int *, int);
int delete(int *, int);
int *reverse(int *, int);
int merge(int *, int);
void search(int *, int);
int *update(int *);
int maximum(int *, int);
int minimum(int *, int);
int main() {
    int n;
    int *n1=&n;
    printf("ENTER THE VALUE OF N: ");
    scanf("%d", &n);
    int *arr = (int *) calloc(n, sizeof(int));
    printf("ENTER THE VALUES: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }


    int ch;



    while (true) {
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. TRAVERSE\n");
        printf("4. REVERSE\n");
        printf("5. MERGE\n");
        printf("6. SEARCH\n");
        printf("7. UPDATE\n");
        printf("8. MAXIMUM ELEMENT\n");
        printf("9. MINIMUM ELEMENT\n");
        printf("10. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                printf("ENTER THE NEW SIZE OF THE ARRAY: ");
                scanf("%d", &(*n1));
                /* so that the newly inserted
                 value can also be reflected during traversal*/
                arr=insert(arr, *n1);
                break;
            }

            case 2:
            {
                *n1=delete(arr, n);
                break;
            }
            case 3:
            {
                traverse(arr, n);
                break;
            }
            case 4:
            {
                arr=reverse(arr, n);
                break;
            }
            case 5:
            {
                *n1=merge(arr, n);
                break;
            }
            case 6:
            {
                search(arr, n);
                break;
            }

            case 7:
            {
                arr=update(arr);
                break;
            }

            case 8:
            {
                int max=maximum(arr, n);
                printf("MAXIMUM ELEMENT = %d\n", max);
                break;
            }

            case 9:
            {
                int min=minimum(arr, n);
                printf("MINIMUM ELEMENT = %d\n", min);
                break;
            }
            case 10:
            {
                exit(0);
            }
        }
    }
}

int *insert(int *arr, int n)
{
    arr=realloc(arr, n*sizeof(int));
    int sum = 0;
    printf("%d", sum);
    int pos, num;
    printf("ENTER THE ELEMENT TO INSERT: ");
    scanf("%d", &num);
    printf("ENTER THE POSITION: ");
    scanf("%d", &pos);

    if(pos>n)
        printf("INVALID POSITION ENTERED\n");

    else
    {
        for(int i=n-1; i>=pos; i--)
        {
            arr[i+1]=arr[i];
        }
        arr[pos]=num;
    }

    return arr;

}

void traverse(int *arr, int n)
{
    for(int i=0; i<n; i++)
        printf("arr[%d] = %d\n", i, *(arr+i));
}

int delete(int *arr, int n)
{
    int pos;
    printf("ENTER THE POSITION TO DELETE: ");
    scanf("%d", &pos);

    for(int i=pos; i<n; i++)
    {
        arr[i]=arr[i+1];
    }

    return n-1;
    /* so that the deleted value
      can also be reflected in traversal*/
}

int *reverse(int *arr, int n)
{
    for(int i=0, j=n-1; j>i; i++, j--)
    {
        int temp=*(arr+i);
        *(arr+i)=*(arr+j);
        *(arr+j)=temp;
    }

    return arr;
}

int merge(int *arr, int n)
{
    int m;
    printf("SIZE OF THE NEW ARRAY: ");
    scanf("%d", &m);
    int *new=(int *)calloc(m, sizeof(int));

    for(int i=0; i<m; i++)
    {
        scanf("%d", (new+i));
    }
    arr=realloc(arr, (n+m)*sizeof(int));

    for(int i=0; i<m; i++)
    {
        arr[n+i]=new[i];
    }

    /* so that the merging can
     be reflected during the traversal */
    n=n+m;
    return n;
}

void search(int *arr, int n)
{
    int elmt, i=0, flag=0;
    printf("ENTER THE ELEMENT TO SEARCH: ");
    scanf("%d", &elmt);

    while(i<n)
    {
        if(arr[i]==elmt)
        {
            flag=1;
            break;
        }
        i=i+1;
    }

    if(flag==1)
        printf("ELEMENT %d FOUND AT INDEX POSITION => %d\n", elmt, i);
    else
        printf("ELEMENT NOT FOUND\n");
}

int *update(int *arr)
{
    int num, pos;
    printf("ENTER THE ELEMENT: ");
    scanf("%d", &num);
    printf("ENTER THE INDEX POSITION TO UPDATE: ");
    scanf("%d", &pos);
    arr[pos]=num;

    return arr;
}
int maximum(int *arr, int n)
{
    int max=arr[0];
    for(int i=0; i<n; i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }

    return max;
}

int minimum(int *arr, int n)
{
    int min=arr[0];
    for(int i=0; i<n; i++)
    {
        if(arr[i]<min)
            min=arr[i];
    }

    return min;
}
