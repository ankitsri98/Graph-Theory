#include<bits/stdc++.h>
using namespace std;
#define ll long long int

//sum shoul also be taken in consideration to to unique elements
ll dp[20][2][180];
bool check(ll x){
    ll last=x%10;
    ll c=0;
    ll b=x;
    while(x>0){
        c++;
        x=x/10;
    }
    ll first=b/pow(10,c-1);
    //cout<<b<<" "<<first<<" "<<last<<endl;
    if(first==last)
    return 1;
    else return 0;
}

ll fun(string s , ll pos=0,ll tight=1,ll t=0,ll sum=0){
    if(pos==s.length()){
        //cout<<t<<endl;
        if(check(t)){
            //cout<<"Sfsdfs "<<t<<endl;
            return 1;
        }
        else return 0;
    }
    if(dp[pos][tight][sum]!=-1)return dp[pos][tight][sum];
    if(tight==1){
        ll ans=0;
        for(int i=0;i<=s[pos]-'0';i++){
            if(i==s[pos]-'0'){
                ans+=fun(s,pos+1,1,t*10+i,sum+i);
            }
            else{
                ans+=fun(s,pos+1,0,t*10+i,sum+i);
            }
        }
        return dp[pos][tight][sum]=ans;
    }
    else{
        ll ans=0;
        for(int i=0;i<=9;i++){
            ans+=fun(s,pos+1,0,t*10+i,sum+i);
        }
        return dp[pos][tight][sum]=ans;
    }
}
void solve(){
    ll n,k,p;
    ll l,r;
    cin>>l>>r;
    l--;
    string a=to_string(l),b=to_string(r);
    //cout<<a<<" "<<b<<endl;
    memset(dp,-1,sizeof(dp));
    k=fun(b);
    memset(dp,-1,sizeof(dp));
    p=fun(a);
    //cout<<k<<" "<<p<<endl;
    k=k-p;
    cout<<k<<endl;
}

int main()
{
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
