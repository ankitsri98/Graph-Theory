/*

The War of Evil vs Good continues and Ra-One and G-One continue to be on respective sides.

After saving all the cities with Ra-One Numbers G-One realised that some cities whose population is a "G-One Number" can be easy target for Ra-One.

A G-One number is a number sum of whose digits is a prime number

For eg. 12 .. sum = 1+2 =3 ... 3 is a prime number.

G-One wants to find out all the populations which can be g-One numbers....

Can You help Him.?
*/



#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
 
ll primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
ll dp[10][80][2];// dp[pos][sum][tight]
 
ll check(ll sum){
    for(auto i:primes){
        if(i==sum)return 1;
    }
    return 0;
}
 
ll g(string s,ll pos=0,ll sum=0,ll tight=1 ){ //tight will be one as 1st digit has restrictions
    if(pos==s.length()){
        if(check(sum)){
            return 1;
        }
        else return 0;
    }
    else if(dp[pos][sum][tight]!=-1)return dp[pos][sum][tight];
    else if(tight==1){ // means for loop will be till that digit and if if there is a boundary condition then forward restriction
        ll tot=0;
        for(ll i=0;i<=s[pos]-'0';i++){
            if(i==s[pos]-'0'){
                tot+=g(s,pos+1,sum+i,1);
            }
            else{
                tot+=g(s,pos+1,sum+i,0);
            }
        }
        return dp[pos][sum][tight]=tot;
    }
    else{
        ll tot=0;
        for(int i=0;i<=9;i++){
            tot+=g(s,pos+1,sum+i,0);
        }
        return dp[pos][sum][tight]=tot;
    }
}
int main() {
	ll n,l,r;
	cin>>n;
	while(n--){
	    cin>>l>>r;
	    string a=to_string(r);
	    string b=to_string(l-1);
	    memset(dp,-1,sizeof(dp));
	    ll p=g(a);
	    memset(dp,-1,sizeof(dp));
	    ll q=g(b);
	    cout<<p-q<<endl;
    }
	return 0;
} 
