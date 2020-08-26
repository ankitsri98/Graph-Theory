/*
World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input
In the first line you'll be given T, number of test cases.

Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.
Output
Print the answers of the queries.
Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
Output:
80  
508
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long  

void update(ll tree[],ll lazy[],int idx,int s,int e,int l,int r,ll val)
{
    if(s>e)
        return;
    if(lazy[idx]!=0)
    {
        ll x =lazy[idx];
        tree[idx]+=(e-s+1)*x;//ADDITION IN RANGE IN O(1) AND THIS IS ADDITION OF RANGE
    
    	if(s!=e)
    	{
    	    lazy[2*idx]+=lazy[idx];//FOR NEXT CALL 
    	    lazy[2*idx+1]+=lazy[idx];
    	}
    	lazy[idx]=0;
    }
    if(s>r||e<l)
        return;
    if(s>=l && e<=r)
    {
        tree[idx]+=(e-s+1)*val;//NOW THE CURRENT VALUE IS BEING ADDED
        if(s!=e)
        {
            lazy[2*idx]+=val;
            lazy[2*idx+1]+=val;
        }
        return ;
    }
    int mid=(s+e)/2;
    update(tree,lazy,2*idx,s,mid,l,r,val);
    update(tree,lazy,2*idx+1,mid+1,e,l,r,val);
    tree[idx]=tree[2*idx]+tree[2*idx+1];//IN THE FOR GROUPING 
    return ;
}
ll query(ll tree[],ll lazy[],int idx,int s,int e,int l,int r)
{
    if(s>e)
        return 0;
    if(lazy[idx]!=0)//IN QUERY PART ALSO THE LAZY LOGIC IS TO BE IMPLEMENTED
    {
        ll x =lazy[idx];
        tree[idx]+=(e-s+1)*x;
    
    	if(s!=e)
    	{
    	    lazy[2*idx]+=lazy[idx];
    	    lazy[2*idx+1]+=lazy[idx];
    	}
    	lazy[idx]=0;
    }
    
	//ABOVE LAZY CODE IS OF UPDATE ONLY
    if(s>r || e<l)
        return 0;
    if(s>=l && e<=r)//IN QUERY PART JUST RETURN 
    {
        return tree[idx];
    }
    int mid=(s+e)/2;
    ll i=query(tree,lazy,2*idx,s,mid,l,r);
    ll j=query(tree,lazy,2*idx+1,mid+1,e,l,r);
    return i+j;
}
int main() 
{
    int t,n,m,i,j,k,x,y;
    ll z;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int a[n]={0};
        ll tree[4*n]={0};
        ll lazy[4*n]={0};
        while(m--)
        {
            cin>>i;
            if(i==0)
            {
                cin>>x>>y>>z;
                update(tree,lazy,1,0,n-1,x-1,y-1,z);
            }
            else
            {
                cin>>x>>y;
                cout<<query(tree,lazy,1,0,n-1,x-1,y-1)<<endl;
            }
        }
    }
    return 0;
}
//refer link https://ideone.com/CiYRHi
