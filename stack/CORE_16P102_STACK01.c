#include<stdio.h>
#include<string.h>
char stack[100];
int top=-1;

void push(char data)
{
    stack[++top]=data;
}

int pop()
{
    int ele;
    ele=stack[top];
    top--;
    return ele;
}


main()
{
    char str[100];
    int i;
    printf("enter string : ");
    scanf("%[^\n\t]s",str);
    for(i=0;i<strlen(str);i++)
    {
        push(str[i]);
    }
    printf("The reversed string is : \n");
    for(i=0;i<strlen(str);i++)
    {
        printf("%c",pop());
    }
}
