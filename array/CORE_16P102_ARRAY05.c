#include<stdio.h>
main()
{
  int n;
  scanf("%d",&n);
  int a[n],i,sum=0;
  for(i=0;i<n-1;i++){
    scanf("%d",&a[i]);
    sum = sum + a[i];
  }
  int s = n*(n+1)/2;
  printf("%d",s-sum);
}