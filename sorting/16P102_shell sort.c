#include<stdio.h>
int arr[100];
void shellsort(int n)
{
    int gap,i;
    for (gap = n/2; gap > 0; gap=gap/2)
    {
        for (i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j=j-gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void print( int n)
{
    int i;
    for (i=0; i<n; i++)
        printf("%d ",arr[i]);
}

int main()
{
    int i,n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    printf("enter the array element\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    shellsort(n);

    printf("\nArray after sorting: \n");
    print( n);

    return 0;
}
