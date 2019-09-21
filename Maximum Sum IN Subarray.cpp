#include<bits/stdc++.h>
using namespace std;

#define MAX_N 50010
struct node{
    int sum,maxsum,maxprefixsum,maxsuffixsum;
};

int a[MAX_N];
node tree[3*MAX_N];


void build(int index,int start,int end)
{
    if(start==end)
    {
        tree[index].sum=a[start];//IF THERE IS ONLY ONE ELEMENT THEN SABHI VAHI HONGE
        tree[index].maxsum=tree[index].maxprefixsum=a[start];
        tree[index].maxsuffixsum=a[start];
        return ;
    }
    int mid=(start+end)/2;
    build(2*index,start,mid);
    build(2*index+1,mid+1,end);
    /*note how we use the array to access the left and right subtree*/
    node left=tree[2*index];//BOTH NODES HAVE ALL THE 4 PARAMEYERS SEPERATELY
    node right=tree[2*index+1];
    //prefix sum is calculated upto some value until -ve number comes and decreases the sum
    tree[index].sum=left.sum+right.sum;//DIRECTLY CALCULAED
    tree[index].maxprefixsum=max(left.maxprefixsum,left.sum+right.maxprefixsum);//YA TOH LEFT SUBTREE KA ZADA HO GAYA YA AGAR LEFT SIDE ME KOI -VE NUMBER HOGA TOH AUR RIGHT SIDE NHI HOGA TOH ...RIGHT WAALE KA PREFIX SUM+LEFT WAALE KA SUM ME 
    tree[index].maxsuffixsum=max(right.maxsuffixsum,right.sum+left.maxsuffixsum);//USI TARAH SUFFIX TERM KO PEEXHE SE DEKHENGE
    tree[index].maxsum=max(tree[index].maxsuffixsum,max(tree[index].maxprefixsum,max(left.maxsum,max(right.maxsum,left.maxsuffixsum+right.maxprefixsum))));
    //MAXSUM ME YA TOH LEFT KA SUM YA RIGHT KA YA LEFT KE RIGHT KA YA RIGHT KE LEFT PART KO ADD KARKE JO BANEGA
    //prefix sum = left subarray + right subarray ka kuch part coz agge number -ve hai
    //suffix sum= right subarray + left ke end ka kuch part
    return ;
    
}
node query(int start,int end,int l,int r,int index)
{
    node result;
    result.sum=result.maxsum=-99999;
    result.maxprefixsum=result.maxsuffixsum=-99999;
    
    if(l>end || r<start)
    {
        return result;
    }
    if(start>=l && end<=r)//REMEMBER THIS LINE 
    {
        return tree[index];
    }
    int mid=(start+end)/2;
    
    node left=query(start,mid,l,r,2*index);
    node right=query(mid+1,end,l,r,2*index+1);
    
    result.sum=left.sum+right.sum;
    result.maxprefixsum=max(left.maxprefixsum,left.sum+right.maxprefixsum);
    result.maxsuffixsum=max(right.maxsuffixsum,right.sum+left.maxsuffixsum);
    result.maxsum=max(result.maxsuffixsum,max(result.maxprefixsum,max(left.maxsum,max(right.maxsum,left.maxsuffixsum+right.maxprefixsum))));

    return result ;
}
int main()
{
    int n,m,i,j,k,x,z,y,q;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    build(1,0,n-1);
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        cout<<query(0,n-1,x-1,y-1,1).maxsum<<endl;
    }
    return 0;
}