/*


Given a set of digits S, and an integer n, you have to find how many n-digit integers are there, 
which contain digits that belong to S and the difference between any two adjacent digits is not more than two.

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

ll dp[12][12];//pos prev
ll g(int n,vector<ll > &v ,ll pos=0,ll prev=0,string s=""){
    if(dp[pos][prev]!=-1){
        return dp[pos][prev];
    }
    if(pos==n){
        //cout<<s<<endl;
        return 1;//1 return karre hain kyuki hum n digit number tabhi bana paige jab poori cond' satisfied ho
	    //yaani  saare adjacent digits diffe. <=2 ho
    }
    ll tot=0;
    for(int i=0;i<v.size();i++){
        if(prev==0 || abs(prev-v[i])<=2){
            tot+=g(n,v,pos+1,v[i],s+to_string(v[i]));// mai function call hi tab karra hoon jab cond' satisfied agar nhi hai toh leave it
        }
    }
    return  dp[pos][prev]=tot;
}
int main() {
	ll n,l,r;
	cin>>n;
	for(int j=1;j<=n;j++){
	    cin>>l>>r;
	    vector<ll  > v(l);
	    for(int i=0;i<l;i++){
	        cin>>v[i];
	    }
	    memset(dp,-1,sizeof(dp));
	    ll p=g(r,v);
	    cout<<"Case "<<j<<":"<<" "<<p<<endl;
    }
	return 0;
}
