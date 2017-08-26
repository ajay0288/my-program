#include<stdio.h>
main()
{
    int n,i,d,r;
    printf("enter size : ");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter how many rotation : ");
    scanf("%d",&d);
    for(r=0;r<d;r++)
    {
        int temp,i;
       for(i=0;i<n-1;i++)
       {
           temp=arr[i];
           arr[i]=arr[i+1];
           arr[i+1]=temp;
       }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
