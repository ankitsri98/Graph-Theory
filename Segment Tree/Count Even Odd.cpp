#include<bits/stdc++.h>
using namespace std;

struct node
{
    int even ;
    int odd;
};
void optimizeIO(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
}
void build(int* a,node* tree, int start,int end,int index )
{
    if(start==end)
    {
        if(a[start]%2==0)//THINK BY KEEPING THE END OF TREE IN MIND i.e 2 ELEMENTS
        {
            tree[index].even+=1;
        }
        else
            tree[index].odd+=1;
        return;
    }
    int mid=(start+end)/2;
    build(a,tree,start,mid,2*index);//here remember tHE CHANGE IN  INDEX
    build(a,tree,mid+1,end,2*index+1);
    
    tree[index].even=tree[2*index].even + tree[2*index+1].even;//THINK BY FORMING PARENT FROM CHILD NODES
    tree[index].odd=tree[2*index].odd +tree[2*index +1].odd;
    
    
}
void update(int* a,node* tree,int start,int end,int index,int idx,int val)//HERE INDEX IS STARTING OF TREE AND IDX IS THE INDEX OF ARRAY
    //TO BE UPDATED ....TAKE CARE
{
    if(start==end)//BASE CASE...
    {
        if(val%2==0 && a[idx]%2!=0)//REMEMBER ARRAY WILL ALSO GET UPDATED IN THIS FUNCTION WITH ITS INDEX i.e IDX
        {
            a[idx]=val;
            tree[index].even+=1;//TREE IS UPDATED WITH ITS INDEX i.e INDEX
            tree[index].odd-=1;
        }
        else if(val%2!=0 && a[idx]%2==0)
        {
            tree[index].odd+=1;
            tree[index].even-=1;
            a[idx]=val;
        }
        else{
            a[idx]=val;
        }
        return ;
    }
    int mid=(start+end)/2;
    if(idx <=mid)//HERE GIVEN INDEX IS USED ONCE AGAIN ...IN ORDER TO CALL FOR 2 HALFS
    {
        update(a,tree,start,mid,2*index,idx,val);    
    }
    else
        update(a,tree,mid+1,end,2*index+1,idx,val);//BASICALLY CURRENT NODE RANGE AND INDEX OF TREE IS UPDATING 

    tree[index].even=tree[2*index].even + tree[2*index+1].even;
    tree[index].odd=tree[2*index].odd +tree[2*index +1].odd;
    
}
node query(node* tree,int start,int end,int l,int r,int treenode)//LOOK IT HAS A RETURN TYPE NODE
{
    node result;
    result.even=0;result.odd=0;//FORM A NODE TO BE RETURNED 
    if(start>r || end<l)//OTSIDE THE RANGE
    {
        return result;
    }
    if(start>=l && end<=r)//COMPLTELLY INSIDE THE RANGE
    {
        return tree[treenode];
    }
    int mid=(start+end)/2;
    node left=query(tree,start,mid,l,r,2*treenode);//SEPERATING NODE AND RANGE CHANGES
    node right=query(tree,mid+1,end,l,r,2*treenode+1);
    
    result.even=left.even + right.even;
    result.odd=left.odd +right.odd;
    
    return result;
}
int main() 
{
    int n,m,x,z,i,j,k,l,y;
    optimizeIO();
    cin>>n;
    int a[n+10];
    for(i=0;i<n;i++)
        cin>>a[i];
    node tree[4*n];
    for(i=0;i<4*n;i++)
    {
        tree[i].even=0;tree[i].odd=0;
    }
    build(a,tree,0,n-1,1);
    cin>>l;
    while(l--)
    {
        cin>>x>>y>>z;
        if(x==0)
            update(a,tree,0,n-1,1,y-1,z);
        else if(x==1){
        	node ans=query(tree,0,n-1,y-1,z-1,1);//PASS INDEX -1 
            cout<<ans.even<<endl;
        }
        else if(x==2){
            node ans=query(tree,0,n-1,y-1,z-1,1);
            cout<<ans.odd<<endl;
        }
    }
    return 0;
	
}
