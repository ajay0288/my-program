#include<stdio.h>
main()
{
    int arr[100],i,n,x,c=0,j;
    printf("enter the size of array : ");
    scanf("%d",&n);

    printf("enter the X element : ");
    scanf("%d",&x);
\
    printf("\n");
    printf("read array elements\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
         {
            if(arr[i]+arr[j]==x)
            {
                c++;
                printf("[%d , %d] ,",arr[i],arr[j]);
            }
         }

    }

    if(c>0)
    {
        printf("are the possible pair\n");
    }
    else
    {
        printf("no pairs found");
    }

}
