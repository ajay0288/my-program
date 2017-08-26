#include<stdio.h>
int stack[100],top=-1;
int count=0;

void push(char data)
{
    stack[++top]=data;
}

int pop()
{
    char ele;
    ele=stack[top--];
    return ele;
}

main()
{
    char str[100];
    int i;
    printf("enter the string : ");
    scanf("%[^\n\t]s",str);
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='(')
           push(str[i]);
        else
        {
            if(str[i]==')'&&pop()=='(')
                count=count+2;
        }
    }

    printf("%d",count);
}
