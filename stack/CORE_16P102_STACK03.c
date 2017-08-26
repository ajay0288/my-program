#include<stdio.h>
int main()
{
    int n,i,fix,j;
    printf("enter stack size : ");
    scanf("%d",&n);
    int stack[n];

    for(i=0;i<n;i++)
    {
        scanf("%d",&stack[i]);
    }
    for (i=0; i<n; i++)
    {
        fix = -1;
        for (j = i+1; j<n; j++)
        {
            if (stack[i] < stack[j])
            {
                fix = stack[j];
                break;
            }
        }
        printf("%d = %d\n", stack[i], fix);
    }
    return 0;
}
