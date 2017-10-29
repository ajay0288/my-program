#include<stdio.h>
#include<stdlib.h>
int pos=0,a[20],n;
void createHeap(int b[],int n)
{
  int i;
  for(i=0;i<n;i++)
	insert(b[i]);
}

void insert(int data)
{
 if(pos==0)
 {
  a[pos+1]=data;
  pos=2;
 }
else
 {
  a[pos++]=data;
  bubbleUp();
 }
}

void bubbleUp()
{
 int p=pos-1;
 while(p>1 && a[p/2]>a[p])
 {
  int y = a[p];
  a[p]=a[p/2];
a[p/2]=y;
  p=p/2;
 }
}
void swap(int x, int y)
{
  int temp = a[x];
  a[x] = a[y];
  a[y] = temp;
}

void sinkDown(int k)
{
 int v=a[k];
 int smallest =k;
 if(2*k<pos && a[smallest]>a[2*k])
 {
  smallest = 2*k;
 }
 if(2*k+1<pos && a[smallest]>a[2*k+1])
{
  smallest = 2*k+1;
 }
 if(smallest!=k)
 {
  swap(k,smallest);
  sinkDown(smallest);
 }
}
void decreasekey(int i,int key)
{
 if(key>a[i])
 {
   printf("New Key is greater than current key");
   return;
 }
a[i]=key;
 while(i>1 && a[i/2]>a[i])
  {
    swap(i,i/2);
    i=i/2;
  }
}
void display()
{
 int i;
 for(i=1;i<=n;i++)
  printf("%d\t",a[i]);
}


int extractMin()
{
 int min = a[1];
 a[1]=a[pos-1];
 a[pos-1]=0;
 pos--;
 sinkDown(1);
 return min;
}



void main()
{
 int i,c[20];
 printf("Enter Size");
 scanf("%d",&n);
 for(i=0;i<n;i++)
  scanf("%d",&c[i]);
 createHeap(c,n);
for(i=0;i<n;i++)
   printf("\nExtract Min: %d",extractMin());
}

