#include<stdio.h>

char stack[100],top=-1;
void push(char data)
{
    if(top==99)
    {
        printf("stack overflow");
        return;
    }
    stack[++top]=data;
}
void pop()
{
    if(top==-1)
    {
        printf("stack underflow");
        return;
    }
    top--;
}
int isempty()
{
    if(top==-1)
        return 0;
}
int findcount(char str[],int len)
{
    int i;
    if (len%2)
       return -1;
    for ( i=0; i<len; i++)
    {
        if (str[i]=='}' && !isempty())
        {
            if (stack[top]=='{')
                pop();
            else
                push(str[i]);
        }
        else
            push(str[i]);
    }

    int slen = top+1;
    int n = 0;
    while (!isempty() && stack[top] == '{')
    {
        pop();
        n++;
    }
    return (slen/2 +n%2);
}

int main()
{
    char str[100];
    printf("enter string : ");
    scanf("%s",str);
    int len=strlen(str);
   int ans=findcount(str,len);
   if(ans==-1)
    printf("not possible\n");
    else
   printf("%d",ans);
   return 0;
}
