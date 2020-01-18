#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int

void update(ll index, ll value,int* bit,ll n)
{
    for(;index<=n;index+=index&(-index))
    {
        bit[index]+=value;
    }
}
ll query(ll index,int* bit)
{
    ll sum=0;
    for(;index>0;index-=index&(-index))
    {
        sum+=bit[index];
    }
    return sum;
}
int main()
{
	ll n;
	cin>>n;
	int * arr=new int[n+1]();
	int * bit=new int [n+1]();
	
	for(int i=1;i<=n;i++)
	{
	    cin>>arr[i];
	    update(i,arr[i],bit,n);
	}
	cout<<"sum of first 5 elements"<<query(5,bit)<<endl;
	cout<<"sum of elemens from 2 to 6 index"<< query(6,bit)-query(1,bit)<<endl;
	return 0;
}
