#include<bits/stdc++.h>
using namespace std ;
#define ll  long long int

ll bit[1000000]={0};
ll b2[1000000]={0};
ll n,q,c;
//takes LOG(N) time
void update(ll bit[],ll i , ll v){
    while(i<=n){
        bit[i]+=v;
        i+= (i&(-i));
    }
}
void range_update(ll l,ll r,ll x){
    update(bit, l, x);
    update(bit, r+1, -x);
    update(b2, l, x*(l-1));
    update(b2, r+1, -x*r);
}
//applying lower bound in BIT
ll find(ll v, ll n){
    ll curr=0,ans=0,prevsum=0;
    for(int i=log2(n);i>=0;i--){
        if(bit[curr+(1<<i)]+prevsum<v){
            curr+=1<<i;
            prevsum+=bit[curr];
        }
    }
    return (curr+1);
}
//can be used as point query
long sum(ll b[],ll idx){
   long total = 0;
    while(idx > 0) {
        total += b[idx];
        idx -= idx & -idx;
    }
    return total;
}
long query(ll idx){
        return sum(bit, idx)*idx -  sum(b2, idx);
    }
long range_query(ll l,ll r){
    return query(r) - query(l-1);
}

int main() {
	ll l,r,v;
	cin>>n>>q;
	
	while(q--){
	    cin>>c;
	    if(c==0){
	        cin>>l>>r>>v;
	        range_update(l,r,v);
	        /*for(int i=1;i<6;i++){
	            cout<<bit[i]<<" ";
	        }
	        cout<<endl;
	        for(int i=1;i<6;i++){
	            cout<<b2[i]<<" ";
	        }
	        cout<<endl;*/
	    }
	    else{
	        cin>>v;
	        int l = 1, h = n; 
            while (l <= h)  
            { 
                int mid = (l + h) / 2; 
                if (query(mid) >= v) 
                    h = mid - 1; 
                else
                    l = mid + 1; 
            } 
            cout<<l<<endl;
	    }
	}
	return 0;
}
