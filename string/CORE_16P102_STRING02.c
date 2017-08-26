#include<stdio.h>
char hash[200]={'0'};
main()
{
   char str[100];
    int i,count=0;
    printf("enter string : ");
    scanf("%[^\n\t]s",str);
    for(i=0;i<strlen(str);i++)
    {
      hash[str[i]]++;
      if(hash[str[i]]>1)
      {
          count=1;
          printf("No");
          break;
      }

    }

if(count==0){
	printf("Yes");
}
}
