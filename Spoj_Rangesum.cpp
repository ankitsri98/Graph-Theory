#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll bit[1000005]={0};
ll n;
//writing code for moving in backward dir^ storing in reverse order
void update(ll i, ll val){
    while(i>0){
        bit[i]+=val;
        i=i-(i&(-i));//from i to 0 index where sum will get added
    }
}
//calculates sum from 1 to i
ll query(ll i){
    i=n-i+1;
    ll sum=0;
    while(i<=n){
        sum+=bit[i];
        i=i+(i&(-i));//search further from where i has caused sum
    }
    return sum;
}
int main() {
    ll m;
    cin>>n;
    for(int i=n;i>=1;i--){//indexing always from 1
        cin>>m;        
        update(i,m);//build BIT
    }
    //queries
    ll q,l,r,s;
    cin>>q;
    while(q--){
        cin>>s;
        if(s==1){
            cin>>l>>r;
            cout<<query(r)-query(l-1)<<endl;
        }
        else{
            ll x;
            cin>>x;n++;
            update(n,x);
        }
    }
}
