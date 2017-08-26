#include<stdio.h>
main()
{
    int n,i;
    printf("enter array size\n");
     scanf("%d",&n);
     int arr[n];
    for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void quicksort(int arr[],int start,int end)
{
    int pivot;
    if(start>end)
      return;
     else
        pivot=choosepivot(arr,start,end);
        quicksort(arr,start,pivot-1);
        quicksort(arr,pivot+1,end);

}

int choosepivot(int arr[],int start,int end)
{
    int i,temp;
    int piv=arr[end];
    int index=start;
    for(i=start;i<end;i++)
    {
        if(arr[i]<=piv)
        {
            temp=arr[i];
            arr[i]=arr[index];
            arr[index]=temp;
            index++;
        }
    }

            temp=arr[index];
            arr[index]=arr[end];
            arr[end]=temp;

            return index;
}


