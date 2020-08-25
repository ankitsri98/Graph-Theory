
#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll arr[100005];
ll bit[100005]={0};

void update(ll i, ll val, ll n){
    while(i<=n){
        bit[i]=max(bit[i],val);
        i=i+(i&(-i));
    }
}
//calculates sum from 1 to i
ll query(ll i){
    ll sum=0;
    while(i>0){
        sum=max(sum,bit[i]);
        i=i-(i&(-i));
    }
    return sum;
}
int main() {
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){//indexing always from 1
        cin>>arr[i];        
        update(i,arr[i],n);//build BIT
    }
    //queries
    ll q,l,r;
    cin>>q;
    while(q--){
        cin>>r;
        cout<<query(r)<<endl;
    }
    
}
