#include<stdio.h>

int hash[100]={0};

main()
{
    int arr[100],i,n,c=0;

    printf("enter size of an array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
                scanf("%d",&arr[i]);
                hash[arr[i]]++;
    }


    for(i=0;i<n;i++)
    {
      if(hash[arr[i]]>n/2)
      {
          printf("%d",arr[i]);
          c=1;
          break;
      }
    }
    if(c==0)
    {
        printf("NONE");
    }

}
