/*
Maximum Pair Sum
Send Feedback
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12
*/
#include <bits/stdc++.h>
using namespace std;
/*Structure to store largest
and second largest value*/
struct node
{
   int first;
   int second;
};
node tree[3*100005];
int arr[100005];
/*This function is used to build the
Segment Tree.*/
void build(int index,int start,int end)
{
   if(start==end)
   {
      tree[index].first = arr[start];
      tree[index].second = INT_MIN;
   }
   else
   {
      int mid = (start+end)/2;
      build(2*index+1,start,mid);
      build(2*index+2,mid+1,end);
      
      tree[index].first = 
         max(tree[2*index+1].first,tree[2*index+2].first);
      tree[index].second = 
         min(max(tree[2*index+1].first,tree[2*index+2].second),
            max(tree[2*index+1].second,tree[2*index+2].first)
            );
   }
}
/*This function is used to answer the queries
that  are there*/
node query(int index,int start,int end,int l,int r)
{
   node result;
   result.first = result.second = -1;
   
   if(start>r || end<l )
      return result;
   if(start>=l && end<=r)
      return tree[index];
   
   int mid = (start+end)/2;
   if(l>mid)
      return query(2*index+2,mid+1,end,l,r);
   if(r<=mid)
      return query(2*index+1,start,mid,l,r);
   
   node left = query(2*index+1,start,mid,l,r);
   node right = query(2*index+2,mid+1,end,l,r);
   
   result.first = 
         max(left.first,right.first);
   result.second = 
         min(max(left.first,right.second),
            max(left.second,right.first)
            );
   return result;
}
/*This function is used to update the value in
the Segment Tree*/
void update(int index,int start,int end,int idx,int value)
{
   if(start == end)
   {
      tree[index].first = value;
      tree[index].second = INT_MIN;
   }
   else
   {
      int mid = (start + end) / 2;
      if(idx <= mid)
         update(2*index+1,start,mid,idx,value);
      else
         update(2*index+2,mid+1,end,idx,value);
      
      tree[index].first = 
         max(tree[2*index+1].first,tree[2*index+2].first);
      tree[index].second = 
         min(max(tree[2*index+1].first,tree[2*index+2].second),
            max(tree[2*index+1].second,tree[2*index+2].first)
            );
   }
}
int main() {
   ios::sync_with_stdio(false);
   int n,q,a,b;
   char ch;
   
   cin>>n;
   for(int i=0;i<n;++i)
      cin>>arr[i];
   build(0,0,n-1);
   cin>>q;
   
   for(int i=0;i<q;++i)
   {
      cin>>ch>>a>>b;
      if(ch=='Q')
      {
         node result = query(0,0,n-1,a-1,b-1);
         cout<<result.first+result.second<<"\n";
      }   
      else
         update(0,0,n-1,a-1,b);
   }
   return 0;
}
