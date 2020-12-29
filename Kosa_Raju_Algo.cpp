#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long int lli;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vop;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define REP(i,a,b) for(long long int i=a;i<b;i++)
#define REPR(i,a,b) for(long long int i=a;i>=b;i--)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define MAX LLONG_MAX
const int mxn=2e5+2;
#define INF 1e18
//----------------------------------------------------------------------------------------
//lower_bound returns an iterator pointing to the first ele. which has a value not less than ‘val
#define LB(arr,n) ll c=0;it=lower_bound(arr.begin(),arr.end(),n);if(it==arr.end()){c=1;}
//define it and if c==1 means not found
#define LB1(arr,n) ll idx=it-arr.begin();if(arr[idx]==n){ idx=idx;}else{idx=idx-1;}
// here idx holds the index( 0 based) of found element
//-----------------------------------------------------------------------------------------
//upper_bound returns an iterator pointing to the first ele. which has a value greater than ‘val’.
#define UB(arr,n) ll c=0;it=upper_bound(arr.begin(),arr.end(),n);if(it==arr.end()){c=1;}
#define UB1(arr,n) ll idx=it-arr.begin();
//-----------------------------------------------------------------------------------------

ll power(ll a,ll b,ll m) { ll ans=1; while(b) { if(b&1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return (ans+m)%m; }
 
ll lcm(ll a, ll b) { return (a*b)/__gcd(a, b); }
 
ll modInverse(ll a, ll m) { ll g = __gcd(a, m); return power(a, m-2, m); } 
 
bool cmp(pair<int ,int > &a,pair<int ,int > & b){
    if(a.second!=b.second){
        return a.first<b.first;
    }
    else{
        return a.second<b.second;
    }
}
//prime factors of 10^18
vector<long long int> genfactors(long long int n){
    vector<long long int> res; 
    long long int val = 2;
    for(long long int i = 2; i*i <= n ; ++i){
        while(n%i == 0){
            res.push_back(i);
            n/=i;
        }
    }
    if(n > 1) res.push_back(n);
    return res;
}
//--------------------------------------------------------------------------------------------


vector< ll > adj[1000005];
vector< ll > tr[1000005];
stack< ll > ord;
vector< ll > vis(1000005);

void dfs1( ll s){
	vis[s]=1;
	for(auto i : adj[s]){
		if(vis[i]==0){
			dfs1(i);
		}
	}
	ord.push(s);
}
void dfs2( ll s , vector< ll  > &d){
	vis[s]=1;
	d.PB(s);
	for(auto i : tr[s]){
		if(vis[i]==0){
			dfs2(i,d);
		}
	}
}
void solve(){
    ll n,x,m,y;
    cin>>n;
    REP(i,0,n){
    	cin>>x;
    	y=i+1+x;
    	adj[i].PB(y%n);
    	tr[y%n].PB(i);
    }
    REP(i,0,n){
    	if(vis[i]==0)dfs1(i);
    }
    REP(i,0,n+2)vis[i]=0;
    ll ans=0;
    while(!ord.empty()){
    	vector< ll > d;
    	//cout<<"dff "<<ord.top()<<endl;
    	if(vis[ord.top()]==0){
    		dfs2(ord.top(),d);
    		if(d.size()==1 && d[0]!=adj[d[0]][0]){//checking for self-loop
			//but if graph does not contain self loops then it will give runtime error
    			continue;
    		}
    		else{
    			ans+=d.size();
    		}
    		//for(auto i : d)cout<<i<<" ";
    	}
    	//cout<<endl;
    	ord.pop();
    	d.clear();
    }
    
    cout<<ans<<endl;
    REP(i,0,n+2)vis[i]=0;
    REP(i,0,n+1){
    	adj[i].clear();
    	tr[i].clear();
    }
    
}
int main()
{
    fastIO;
    ll t=1;
    cin >> t;
    while(t--)
    {
        solve();   
    }
    return 0;
}




