#include <bits/stdc++.h>
using namespace std;

class trienode{
public:
    trienode* left;
    trienode* right;
    int countl=0;
    int countr=0;//every bit node has left and right count variable with zero initialisation
};
void insert(int n,trienode* head)
{
    trienode* curr=head;
    for(int i=20;i>=0;i--)
    {
        int b=(n>>i)&1;
        if(b==0)
        {
            curr->countl++;
            if(!curr->left){
                curr->left=new trienode;
            }
            curr=curr->left;
        }
        else
        {
            curr->countr++;
            if(!curr->right){
                curr->right=new trienode;
            }
            curr=curr->right;
        }
        //cout<<"curr-left: "<<curr->countl<<"  curr-right: "<<curr->countr<<endl;
    }
}

int find_max_xor(trienode* head,int val,int k)
{
        int value=val;
        trienode* curr=head;
        int ans=0;
        for(int j=20;j>=0;j--)
        {
            int b=(value>>j)&1;//present value
            int q=(k>>j)&1;// kth value
            //cout<<b<<" ";
            if(q==1 && b==1)//q ko zero banane ke liye 1 select karna hai toh right subtree ka count add karlenge aur left move kar jaige
            {
                ans+=curr->countr;
                if(!curr->left)
                    return ans;
                curr=curr->left;
            }
            else if(q==1 && b==0)//q lo zero banane ke liye with the  help of zero 0 milna chahiye toh left subtree ka amt add karlenge aur right move karjao
            {
                ans+=curr->countl;
                if(!curr->right)
                    return ans;
                curr=curr->right;
            }
            else if(q==0 && b==1)//yahaan par q already zero hai toh bas ye decide karo ki kidhar move karna hai..aur zero hi rehna chahiye toh right
            {
                if(!curr->right)
                    return ans;
                curr=curr->right;
            }
            else if(q==0 && b==0)//to maintain 0 with 0 move left
            {
                if(!curr->left)
                    return ans;
                curr=curr->left;
            }
        }
        return ans;
}
int main()
{
    int n,p=0,t,k;
    cin>>t;
    while(t--)
    {
        p=0;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        trienode* head=new trienode();
        insert(0,head);
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            p=p^arr[i];
            //cout<<"p: "<<p<<endl;
            ans+=find_max_xor(head,p,k);//PEHLE INSERT PHIR SEARCH TOH HAR BAAR ZERO AAIGA KYUKI HAR BAAR
            //SAME  ELEMENT SE XOR HOJAIGA.....TOH PEHLE LASTLY ENTERED VALUES SE XOR KAR PHIR NEWW WALA INSER TKARO
            insert(p,head);
            //cout<<"ans: "<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;   
}

