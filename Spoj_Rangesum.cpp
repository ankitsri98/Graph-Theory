/*
Problem Statement
You are initially given an array of N integers ( 1<=N<=105 ). Given this array, you have to perform 2 kinds of operations :

(i) Operation 1 : Op1( l, r )

You are given 2 integers l and r. ( 1 <= l <= r <= current size of the array ). You need to return the sum of all the elements with indices between l and r ( both inclusive ). That is, if the elements currently in the array are a1, a2, a3.... an, you need to return the following sum : al + al+1 + al+2 ... + ar.

(ii) Operation 2 : Op2( x )

You are given a single integer x ( |x| <= 109 ). Add this element to the beginning of the array. After this operation, x will now become a1, the old a1 will now become a2, and so on. The size of the array will increase by 1.


Input
The first line contains a single integer N ( 1 <= N <= 105 ), the number of elements initially in the array.

This is followed by a line containing N space separated integers, a1 a2 .... aN. ( |ai| <= 109 )

The next line contains a single integer Q, the number of operations you will be asked to perform. ( 1 <= Q <= 105 )

Q lines of input follow. Each such line starts with either the number 1 or the number 2. This indicates the type of operation that you are required to perform. The format of these queries are as follows :

1 l r : Carry out operation 1 with arguments l and r. ( 1 <= l <= r <= current size of the array )
That is, return the sum of the following array elements : al + al+1 ... + ar

2 x : Carry out operation 2 with the argument x. ( |x| <= 109 )
That is, add the value x at the beginning of the array.

Output
For each query of type 1, output the return value on a new line. No output needs to be printed for queries of type 2.

Example
Input #1:
10
1 2 3 4 5 6 7 8 9 10
4
1 1 10
1 1 1
1 10 10
1 2 7
Output #1:
55
1
10
27
Input #2:
5
6 7 8 9 10
9
2 5
2 4
1 2 7
2 3
2 2
2 1
1 1 10
1 1 1
1 10 10
Output #2:
45
55
1
10

*/


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
