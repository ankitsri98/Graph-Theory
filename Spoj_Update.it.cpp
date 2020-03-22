#include <bits/stdc++.h>
using namespace std;
#define ll long long 


ll bit[100005]={0};

void update(ll i, ll val, ll n){
    while(i<=n){
        bit[i]+=val;
        i=i+(i&(-i));
    }
}
//calculates sum from 1 to i---------RANGE SUM QUERY
ll query(ll i){
    ll sum=0;
    while(i>0){
        sum+=bit[i];
        i=i-(i&(-i));
    }
    return sum;
}
int main() {
    ll n,u,q,l,r,x,t;
    cin>>t;
    while(t--){
        memset(bit,0,sizeof(bit));
        cin>>n>>u;
        while(u--){
            cin>>l>>r>>x;
            update(l+1,x,n);
            update(r+1+1,-1*x,n);
        }
        /*for(int i=1;i<=n;i++){
            cout<<bit[i]<<endl;
        }*/
        cin>>q;
        while(q--){
            cin>>x;
            cout<<query(x+1)<<endl;
        }
    }
}
