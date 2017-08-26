#include<stdio.h>
#include<string.h>
char st[100];
int top=-1;
    char hash[200]={'0'};
int reverse3(char str[])
{

    char exp[100];
    strcpy(exp,str);
    int i;
    for(i=0;i<strlen(exp);i++)
    {
      hash[exp[i]]++;
    }

    for(i=strlen(exp);i>=0;i--)
    {

        if(hash[exp[i]]>0)
        {
            printf("%c",exp[i]);
            hash[exp[i]]=0;
        }
    }

}
void reverse1(char str[])
{
    int i,j,r=0,k;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]==32)
        {
            j=i-1;
            while(j>=r)
            {
                printf("%c",str[j]);
                j--;
            }
            printf(" ");
            r=i+1;
        }
        if(i==strlen(str)-1)
        {
            k=i;
            while(k>=r)
            {
                printf("%c",str[k]);
                k--;
            }

}

}
}
int reverse2(char str[])
{
    char arr[100]={0};
    int i,j=0,k=0;
    for(i=strlen(str)-1;i>=0;i--)
    {
        if(i==0)
        {
            arr[k]=str[i];
        }
        if(str[i]==' ' || i==0)
        {
            for(j=strlen(arr)-1;j>=0;j--)
            {
            printf("%c",arr[j]);
            }
            printf(" ");
            k=0;
        }
        else
        {
            arr[k]=str[i];
            k++;
        }

    }
    return 1;
}

void reversevowel(char str[])
{
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
         st[++top]=str[i];
    }

    for(i=0;i<strlen(str);i++)
    {
      if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
         printf("%c",st[top--]);
       else
         printf("%c",str[i]);
    }
    }


int main()
{
    int choice,str[100];
    printf("enter string : ");
    scanf("%[^\n\t]s",str);
    while(1)
    {
    printf("\n1.reverse1\n2.reverse2\n3.reverse3\n4.reversevowel\nenter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        reverse1(str);
        break;
    case 2:
        reverse2(str);
        break;
    case 3:
        reverse3(str);
        break;
    case 4:
        reversevowel(str);
        break;
    }
    }
    printf("\n");

    return 0;
}

