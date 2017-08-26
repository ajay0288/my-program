#include<stdio.h>
int hash[100]={0};
int size;
int i=0;

void insert(int key)
{
    if(hash[((key)%size+i)%size]==0)
    {
       hash[((key)%size+i)%size]=key;
    }
    else
    {
        i=i+1;
        while(i<size)
        {
                if(hash[(key%size+i)%size]==0)
                 {
                  hash[((key)%size+i)%size]=key;
                  return;
                 }
                 i++;
        }
    }
}

void delet(int key)
{
    int flag=0;
    if(hash[((key)%size+i)%size]==key)
    {
       hash[((key)%size+i)%size]=0;
       printf("key succesfully deleted\n");
       flag=1;
       return;
    }
    else
    {
        i=i+1;
        while(i<size)
        {
                if(hash[((key)%size+i)%size]==key)
                 {
                  hash[((key)%size+i)%size]=0;
                  printf("key succesfully deleted\n");
                  flag=1;
                  return;
                 }
                 i++;
        }
    }
    if(flag==0)
    {
        printf("key not present in the hash table\n");
    }
}

void search(int key)
{
    int flag=0;
    if(hash[((key)%size+i)%size]==key)
    {
       printf("key is present at hash[%d]\n",((key)%size+i)%size);
       flag=1;
       return;
    }
    else
    {
        i=i+1;
        while(i<size)
        {
                if(hash[((key)%size+i)%size]==key)
                 {
                  printf("key is present at hash[%d]\n",((key)%size+i)%size);
                   flag=1;
                   return;
                 }
                 i++;
        }
    }
    if(flag==0)
    {
        printf("key not present in the hash table\n");
    }
}

void display()
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",hash[i]);
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
                printf("enter the key to be searched");
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
