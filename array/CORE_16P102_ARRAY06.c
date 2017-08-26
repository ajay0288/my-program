#include<stdio.h>
main()
{
 int n;
 printf("enter size of an array : ");
 scanf("%d",&n);
 printf("enter array elements : \n");
 int arr[n],b[n],i,j;
 for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
 for(i=n-1,j=0;i>=0;i--,j++)
   b[j] = arr[i];
 for(i=0;i<n;i++)
   printf("%d ",b[i]);

}
