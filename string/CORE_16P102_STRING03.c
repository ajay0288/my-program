#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int count=0;
main()
{
    int i;
    int arr[100],k=0,r=0,l=0;
    char t1[100],t2[100][100],tr[100];
    printf("enter string : ");
    scanf("%s",t1);
    for(i=0;i<strlen(t1);i++)
    {
        if(isdigit(t1[i]))
        {
            arr[k++]=t1[i]-48;
            count++;
        }
        else if(t1[i]>='a'&&t1[i]<='z'||t1[i]>='A'&&t1[i]<='Z')
        {
            tr[r++]=t1[i];
        }
        else if(t1[i]=='['&&r!=0||t1[i]==']'&&r!=0)
        {
            tr[r]=NULL;
            strcpy(t2[l],tr);
            l++;
            r=0;
        }
    }
  int j,m=0;
    for(i=count;i>=0;i--)
    {
        char t3[100];
        strcpy(t3,t2[l]);
        for(j=0;j<arr[i]-1;j++)
        {
            strcat(t2[l],t3);
        }
        l--;
        strcat(t2[l],t2[l+1]);
    }
    printf(" %s ",t2[0]);
}
