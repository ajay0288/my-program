#include<stdio.h>
int arr[100],seg[100];
int constructsegment(int arr[],int seg[],int start,int end,int pos){
    int mid = (start+end)/2;
    if(start==end){
        seg[pos]=arr[end];
        return arr[end];
    }
    else{
    int left = constructsegment(arr,seg,start,mid,2*pos);
    int right = constructsegment(arr,seg,mid+1,end,2*pos+1);
    seg[pos]=left+right;
    return seg[pos];
    }
}

int query(int seg[],int nstart,int nend,int qstart,int qend,int pos){
    if (qstart <= nstart && qend >= nend)
            return seg[pos];
        if (nend < qstart || nstart > qend)
            return 0;
        int mid = (nstart+nend)/2;
        return query(seg, nstart, mid, qstart, qend, 2*pos) + query(seg, mid+1, nend, qstart, qend, 2*pos+1);
}

int getSum(int seg[], int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return query(seg, 1, n, qs, qe, 1);
}

int updateSeg(int seg[],int index,int ele,int start,int end,int pos){
int mid=(start+end)/2;
if(index<start||index>end){
return;
}
seg[pos]+=ele;
if(end!=start){
updateSeg(seg,index,ele,start,mid,pos*2);
updateSeg(seg,index,ele,mid+1,end,(pos*2)+1);
}
}

int update(int index,int ele,int arr[],int seg[],int n){
 int up = ele-arr[index];
 updateSeg(seg,index,up,1,n,1);
}

main(){
arr[0]=0;
int i,n;
scanf("%d",&n);
for(i=1;i<=n;i++){
scanf("%d",&arr[i]);
}
constructsegment(arr,seg,1,n,1);
int res = getSum(seg,n,1,4);
printf("%d\n",res);
update(1,10,arr,seg,n);
res = getSum(seg,n,1,4);
for(i=1;i<=2*n-1;i++){
printf("%d ",seg[i]);
}
printf("\n%d",res);
}
