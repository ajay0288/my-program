#include<stdio.h>
main()
{
    int arr[100],i,n,x=0;

    printf("enter size of an array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        x=x^arr[i];
    }
    printf("%d",x);
}
