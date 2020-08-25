/*
You have an array containing n elements initially all 0. You need to do a number of update operations on it. In each update you specify l, r and val which are the starting index, ending index and value to be added. After each update, you add the 'val' to all elements from index l to r. After 'u' updates are over, there will be q queries each containing an index for which you have to print the element at that index.

Input
First line consists of t, the number of test cases. (1 <= t <= 10)

Each test case consists of "n u",number of elements in the array and the number of update operations, in the first line (1 <= n <= 10000 and 1 <= u <= 100000)

Then follow u lines each of the format "l r val" (0 <= l,r < n, 0 <= val <=10000)

Next line contains q, the number of queries. (1 <= q <= 10000)

Next q lines contain an index (0 <= index < n)

Output
For each test case, output the answers to the corresponding queries in separate lines.

Example
Input:
1
5 3
0 1 7
2 4 6
1 3 2
3
0
3
4

Output:
7
8
6

*/

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
