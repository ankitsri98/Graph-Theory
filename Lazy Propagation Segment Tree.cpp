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
void updatesegmenttree(int *tree,int* lazy,int low,int high,int startr,int endr,int currpos,int inc)
{
    if(low>high)
    {
        return;
    }
    if(lazy[currpos]!=0)
    {
        tree[currpos]+=lazy[currpos];
        if(low!=high){
            lazy[2*currpos]+=lazy[currpos];
            lazy[2*currpos+1]+=lazy[currpos];
        }
        lazy[currpos]=0;
    }
    //NO OVERLAP
    if(startr>high || endr<low)
    {
        return ;
    }
    //COMPLETE
    if(startr<=low && high<=endr)
    {
        tree[currpos]+=inc;
        if(low!=high){
            lazy[2*currpos]+=inc;
            lazy[2*currpos+1]+=inc;
        }
        return ;
    }
    //PARTIAL OVERLAP
    int mid=(low+high)/2;
    updatesegmenttree(tree,lazy,low,mid,startr,endr,2*currpos,inc);
    updatesegmenttree(tree,lazy,mid+1,high,startr,endr,2*currpos+1,inc);

    tree[currpos]=min(tree[2*currpos],tree[2*currpos+1]);
}
int main()
{
    int arr[]={1,-3,2,4};
    int* tree = new int[12]();
    buildtree(arr,tree,0,3,1);
    int* lazy=new int[12]();
    updatesegmenttree(tree,lazy,0,3,0,3,1,3);
    updatesegmenttree(tree,lazy,0,3,0,1,1,2);
    for(int i=1;i<12;i++)
    {
        cout<<tree[i]<<"  ";
    }
    cout<<endl;
    for(int i=1;i<12;i++)
    {
        cout<<lazy[i]<<"  ";
    }

    return 0;
}
