#include <stdio.h>
int main()
{
    int n,i;
    printf("enter the size of an array : ");
    scanf("%d",&n);
    int arr[n];
     int tmp[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Array before sorting:\n");
    display(arr,n);
    mergesort(arr, tmp, n);

    printf("Array after sorting:\n");
    display(arr,n);

    return 0;
}

void mergesort(int arr[], int tmp[],int n)
{
    msort(arr, tmp, 0, n - 1);
}

void msort(int arr[], int tmp[], int left, int right)
{
    int mid;
    if (right > left)
    {
        mid = (right + left) / 2;
        msort(arr, tmp, left, mid);
        msort(arr, tmp, mid + 1, right);
        merge(arr, tmp, left, mid + 1, right);
    }
}

void merge(int arr[], int tmp[], int left, int mid, int right)
{
    int i, lend,lfirst,rfirst,rend,count,tmppos;
    lfirst=left;
    lend = mid - 1;
    rfirst=mid;
    rend=right;
    tmppos = left;
    count = right - left + 1;

    while ((lfirst <= lend) && (rfirst <= right))
    {
        if (arr[lfirst] <= arr[rfirst])
        {
            tmp[tmppos] = arr[lfirst];
            tmppos = tmppos + 1;
            lfirst = lfirst +1;
        }
        else
        {
            tmp[tmppos] = arr[rfirst];
            tmppos = tmppos + 1;
            rfirst = rfirst + 1;
        }
    }

    while (lfirst <= lend)
    {
        tmp[tmppos] = arr[lfirst];
        lfirst = lfirst + 1;
        tmppos = tmppos + 1;
    }
    while (rfirst <= rend)
    {
        tmp[tmppos] = arr[rfirst];
        rfirst = rfirst + 1;
        tmppos = tmppos + 1;
    }

    for (i = 0; i <= count; i++)
    {
        arr[rend] = tmp[rend];
        rend = rend - 1;
    }
}

void display(int arr[],int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ",arr[i]);

    printf("\n");
}
