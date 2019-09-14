#include<bits/stdc++.h>
using namespace std;

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

    tree[treenode]= tree[2*treenode]+ tree[2*treenode+1];

}
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
    tree[treenode]=tree[2*treenode]+tree[2*treenode+1];
}
int main()
{
    int arr[]={1,2,3,4,5};
    int* tree = new int[10];
    buildtree(arr,tree,0,4,1);
    updatetree(arr,tree,0,4,1,2,10);
    for(int i=1;i<10;i++)
    {
        cout<<tree[i]<<"  ";
    }

    return 0;
}
