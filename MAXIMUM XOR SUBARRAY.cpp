#include <bits/stdc++.h>
using namespace std;

class trienode{
public:
    trienode* left;
    trienode* right;
};

void insert(int n,trienode* head)
{
    trienode* curr=head;
    for(int i=31;i>=0;i--)
    {
        int b=(n>>i)&1;
        if(b==0)
        {
            if(!curr->left){
                curr->left=new trienode;
            }
            curr=curr->left;
        }
        else
        {
            if(!curr->right){
                curr->right=new trienode;
            }
            curr=curr->right;
        }
    }
}

int find_max_xor(trienode* head,int val)
{
        int value=val;
        trienode* curr=head;
        int curr_xor=0;
        for(int j=31;j>=0;j--)
        {
            int b=(value>>j)&1;

            if(b==0)
            {
                if(curr->right)
                {
                    curr_xor+=pow(2,j);
                    curr=curr->right;
                }
                else
                {
                    curr=curr->left;
                }
            }
            else
            {
                if(curr->left)
                {
                    curr_xor+=pow(2,j);
                    curr=curr->left;
                }
                else
                {
                    curr=curr->right;
                }
            }
        }
        return curr_xor;
}
int main()
{
    int n,p=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    trienode* head=new trienode();
    insert(0,head);
    int ans=0;
    for(int i=0;i<n;i++)//AS EXPLAINED IN HINT VIDEO THAT FOR ANY NEW NUMBER LIKE 1  8 2 ->5 XOR OF 1^8^2^5 IS PASSED THEN
    {                   //THEN IT RETURNS MAX_XOR BY COMPARING IT WITH 1, 1^8, 1^8^2, COSIDERING XOR AS A SINGLE VALUE 1,9,11
        p=p^arr[i];    
        insert(p,head);
        ans=max(ans,find_max_xor(head,p));
    }
    cout<<ans<<endl;
    return 0;
}
