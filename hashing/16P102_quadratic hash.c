#include<stdio.h>
int hash[100]={0};
int size;

void insert(int key)
{
    int i=0,flag=1;
        if(hash[((key)%size+(i*i))%size]==0)
           {
            hash[((key)%size+(i*i))%size]=key;
            flag=0;
           }
        else
         {
        i=i+1;
        flag=1;
        while(flag)
        {
                if(hash[(key%size+(i*i))%size]==0)
                 {
                  hash[((key)%size+(i*i))%size]=key;
                  flag=0;
                  return;
                 }
                 i++;
        }
    }
    }

void delet(int key)
{
    int flag=1;
    int i=0;
    if(hash[((key)%size+(i*i))%size]==key)
    {
       hash[((key)%size+(i*i))%size]=0;
       printf("key succesfully deleted\n");
       flag=0;
       return;
    }
    else
    {
        i=i+1;
        flag=1;
        while(flag)
        {
                if(hash[((key)%size+(i*i))%size]==key)
                 {
                  hash[((key)%size+(i*i))%size]=0;
                  printf("key succesfully deleted\n");
                  flag=0;
                  break;
                 }
                 i++;
        }
    }
    if(flag==1)
    {
        printf("key not present in the hash table\n");
    }
}

void search(int key)
{
    int flag=1;
    int i=0;
    if(hash[((key)%size+(i*i))%size]==key)
    {
       printf("key is present at hash[%d]\n",((key)%size+(i*i))%size);
       flag=0;
       return;
    }
    else
    {
        i=i+1;
        flag=1;
        while(flag)
        {
                if(hash[((key)%size+(i*i))%size]==key)
                 {
                  printf("key is present at hash[%d]\n",((key)%size+(i*i))%size);
                   flag=0;
                   return;
                 }
                 i++;
        }
    }
    if(flag==1)
    {
        printf("key not present in the hash table\n");
    }
}

void display()
{
    int i;
    for(i=0;i<100;i++)
    {
        if(hash[i]!=0)
        {
        printf("hash[%d]=%d\n",i,hash[i]);
        }
    }
    printf("\n");
}

main()
{
    printf("enter the size of hash table\n");
       scanf("%d",&size);
    int choice;
    while(1)
    {
        printf("1.insert\n2.delete\n3.search\n4.display\n\tenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                int key;
                printf("\tenter the key to be inserted:");
                scanf("%d",&key);
                insert(key);
            }
            break;
        case 2:
            {
                int del;
                printf("\tenter the key to be deleted: ");
                scanf("%d",&del);
                delet(del);
            }
             break;
        case 3:
            {
                int key;
                printf("enter the key to be searched: ");
                scanf("%d",&key);
                search(key);
            }
            break;
        case 4:
            {
                display();
            }
            break;
        default:
            printf("wrong choice");
            break;
        }
    }
}

