#include<bits/stdc++.h>
using namespace std;
#define  ll long long int

//FOR BUILDING  IT TAKES O(N)
void buildtree(int* arr,int* tree,int start,int en,int treenode)
{
    if(start==en)
    {
        tree[treenode]=arr[start];
        return ;
    }
    int mid=(start+en)/2;

    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,en,2*treenode+1);

    tree[treenode]= min(tree[2*treenode], tree[2*treenode+1]);

}
//FOR UPDATING IT TAKES O(LOG N)
void updatetree(int* arr,int *tree,int start,int en,int treenode,int idx,int value)
{
    if(start==en)
    {
        arr[idx]=value;
        tree[treenode]=value;
        return;
    }
    int mid=(start+en)/2;
    if(idx>mid)
    {
        updatetree(arr,tree,mid+1,en,2*treenode+1,idx,value);
    }
    else
    {
        updatetree(arr,tree,start,mid,2*treenode,idx,value);
    }
    tree[treenode]= min(tree[2*treenode], tree[2*treenode+1]);
}
//FOR QUERYING ALSO IT TAKES O(LOG N)
int query(int* tree,int start,int en,int treenode,int left,int right)
{
    //COMPLETELY OUTSIDE GIVEN RANGE
    if(start > right || en < left){//  END  LEFT     RIGHT   START
        return INT_MAX;
    }
    //COMPLTELY INSIDE THE GIVEN RANGE
    if(start>=left && en<=right){//CONSIDERING THAT THE RANGE FOR WHICH THE  SUM IS STORED AT TREENODE
        return tree[treenode]; //HAS TO BE INSIDE THE  GIVEN RANGE TO BE FIND
    }
    //PARTIALLY INSIDE AND PARTIALLY OUTSIDE
    int mid =(start+en)/2;
    int ans1=query(tree,start,mid,2*treenode,left,right);
    int ans2=query(tree,mid+1,en,2*treenode+1,left,right);
    return min(ans1,ans2);

}
int main() 
{
    ll n,m,q,x,z,k,i,j,y;
    cin>>n>>q;
    int a[n];
    int* tree=new int[4*n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    buildtree(a,tree,0,n-1,1);
    while(q--)
    {
        char ch;
        cin>>ch>>x>>y;
        if(ch=='q')
        {
            cout<<query(tree,0,n-1,1,x-1,y-1)<<endl;//CATCH IS THAT HERE ARRAY IS 0 BASED INDEXING AND TREE IS 1 BASE INDEXING SO,
        }
        else if(ch=='u')                         //PASS ALL INDEX 1 LESS 
        {
            updatetree(a,tree,0,n-1,1,x-1,y);//BUT HERE Y IS VALUE TO BE UPDATED SO IT WILL NOT DECREASE BY ONE 
        }
    }
    
return 0;
	
}