
#include<bits/stdc++.h>
using namespace std;
#define  ll long long int

struct treenode{
    ll sqsum;
    ll tsum;
};

struct lazynode{
    ll set;//SET CONTAINS THE VALUE TO BE SET
    ll update;//THIS HOLDS VALUE TO BE UPDATED MEANS ADDED
};

void maketree(int s,int e,int i, treenode* tree, ll* arr)
{
    if(s==e)//WHEN LEFT AND RIGHT SUBARRAY HAS ONLY ONE ELEMENT EACH
    {
        tree[i].sqsum=arr[s-1]*arr[s-1];
        tree[i].tsum=arr[s-1];
        return;
    }
    int mid=(s+e)/2;
    maketree(s,mid,2*i,tree,arr);
    maketree(mid+1,e,2*i+1,tree,arr);
    
    tree[i].sqsum=tree[2*i].sqsum + tree[2*i+1].sqsum;//REMEMBER TO USE STRUCTURE ELEMENTS WILL ALL
    tree[i].tsum=tree[2*i].tsum + tree[2*i+1].tsum;
}

void update(int s,int e,int l,int r,ll v,int qtype,int i,treenode* tree , lazynode* lazytree)
{
    if(s>e)
        return;
    if(lazytree[i].set!=0)//CHECK IF VALUE IS PRESENT OR NOT...BEFORE EXECUTION
    {
        ll x=lazytree[i].set;
        tree[i].tsum=x*(e-s+1);//UPDATE THE VALUE TO PRESENT INDEX 
        tree[i].sqsum=x*x*(e-s+1);
        if(s!=e)//CHECKING IF ITS NOT LEAF NODE
        {
            lazytree[2*i].update=0;//COZ ITS 0TH QUERY NUMBER
            lazytree[2*i].set=x;
            lazytree[2*i+1].update=0;
            lazytree[2*i+1].set=x;
        }
        lazytree[i].set=0;//VALUE IS USED SO MAKE IT ZERO
    }
    if(lazytree[i].update!=0)//UPDATE QUERY
    {
        ll x=lazytree[i].update;
        tree[i].sqsum+=x*x*(e-s+1)+ 2*x*(tree[i].tsum);//EVERY NODE HAS SUM AND SQUARE SUM SO THINK VALUE IS INC BY X AND INITIALY THAT POS.
        //CONTAINS A THEN FINALLY ITS (A+X)^2=A^2 + X^2 + 2*X*(SUM OF ARRAY WHICH IS STORED AT THAT NODE ADD IT AND USE )
        tree[i].tsum+=x*(e-s+1);// AS VALUES ARE CHANGED FROM A TO A+X... SO AT THAT POS. SUM ALSO CHANGES ....LIKE THIS
        if(s!=e)
        {
            lazytree[2*i].update+=x;
            lazytree[2*i+1].update+=x;
        }
        lazytree[i].update=0;
    }
    if(e<l || s>r)//OUTSIDE THE RANGE
    {
        return ;
    }
    if(s>=l && e<=r)//COMPLETELY INSIDE SO HERE YOU WILL UPDATE THE VALUE GIVEN IN 
                    //QUERY AND ADD IT FURTHUR TO THE CHILD NODES OF LAZY TREE
    {
        if(qtype==0)//MEANS SET QUERY
        {
            tree[i].tsum=v*(e-s+1);
            tree[i].sqsum=v*v*(e-s+1);
            if(s!=e)
            {
                lazytree[2*i].update=0;
                lazytree[2*i].set=v;
                lazytree[2*i+1].update=0;
                lazytree[2*i+1].set =v;
            }
        }
        else
        {
            tree[i].sqsum+=v*v*(e-s+1) + 2*v*(tree[i].tsum);
            tree[i].tsum+=v*(e-s+1);
            if(s!=e)
            {
                lazytree[2*i].update+=v;
                lazytree[2*i+1].update+=v;
            }
        }
        return ;
    }
    int mid=(s+e)/2;
    update(s,mid,l,r,v,qtype,2*i,tree,lazytree);
    update(mid+1,e,l,r,v,qtype,2*i+1,tree,lazytree);
    tree[i].tsum=tree[2*i].tsum + tree[2*i+1].tsum;
    tree[i].sqsum=tree[2*i].sqsum + tree[2*i+1].sqsum;
}

ll query(int s,int e,int l,int r,int i,treenode* tree, lazynode* lazytree )
{
    if(s>e) return 0;
    if(lazytree[i].set!=0)//IN QUERY SECTION ALSO FIRST THE EXISTING VALUES AT LAZYTREE INDEX IS CHECKED

    {
        ll x=lazytree[i].set;
        tree[i].tsum=x*(e-s+1);
        tree[i].sqsum=x*x*(e-s+1);
        if(s!=e)
        {
            lazytree[2*i].update=0;
            lazytree[2*i].set=x;
            lazytree[2*i+1].update=0;
            lazytree[2*i+1].set=x;
        }
        lazytree[i].set=0;
    }
    if(lazytree[i].update!=0)
    {
        ll x=lazytree[i].update;
        tree[i].sqsum+=x*x*(e-s+1)+ 2*x*(tree[i].tsum);
        tree[i].tsum+=x*(e-s+1);
        if(s!=e)
        {
            lazytree[2*i].update+=x;
            lazytree[2*i+1].update+=x;
        }
        lazytree[i].update=0;
    }
    //COMPLETION OF INITIAL CONDITONS IS OVER
    if(e<l || s>r)
    {
        return 0;
    }
    if(s>=l && e<=r)//OUT OF RANGE
    {
        return tree[i].sqsum;//COMPLETELY INSIDE
    }
    int mid=(s+e)/2;
    ll a1=query(s,mid,l,r,2*i,tree,lazytree);
    ll a2=query(mid+1,e,l,r,2*i+1,tree,lazytree);
    return a1+a2;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"Case "<< i+1<<":"<<endl;
        int n,q;
        cin>>n>>q;
        ll arr[n];
        for(int j=0;j<n;j++)
            cin>>arr[j];
        treenode tree[4*n];
        maketree(1,n,1,tree,arr);//BUILDING TREE 
        lazynode lazytree[4*n];
        for(int j=0;j<4*n;j++)
        {
            lazytree[j].set=0;
            lazytree[j].update=0;
        }
        
        for(int j=0;j<q;j++)
        {
            int qtype;
            cin>>qtype;
            if(qtype==0 || qtype==1)
            {
                int l,r;
                ll v;
                cin>>l>>r>>v;
                update(1,n,l,r,v,qtype,1,tree,lazytree);
            }
            else if(qtype==2)
            {
                int l,r;
                cin>>l>>r;
                cout<<query(1,n,l,r,1,tree,lazytree)<<endl;
            }
        }
    }
}


