#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int d)
    {
        data=d;left=NULL,right=NULL;
    }
};

node* buildtree(){
    int d;
    cin>>d;
    
    if(d==-1){ 
        //-1 means end
        return NULL;
    }
    
    node * root=new node(d);
    //root->left= as i am storing values
    root->left=buildtree();//left subtree
    root->right=buildtree();//right subtree
 
    return root;
}

int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}
void Print_kth_level(node* root,int k)
{
    if(root==NULL){
        return ;
    }
    if(k==1)
    {
        cout<<root->data<<" ";//we print any node at level k from its "parent call to child" first 'left' "found->print" not found then from parent 
        return;// to other child
    }
    Print_kth_level(root->left,k-1);
    Print_kth_level(root-> right,k-1);
    return;
}
void Print_all_levels(node* root)//complexity is O(N^2) in case of right or left skewed tree.
{
    int x=height(root);
    for(int i=1;i<=x;i++)
    {
        cout<<i<<" level is: "<<" ";
        Print_kth_level(root,i);
        cout<<endl;
        
    }
}
int main() 
{
	node* root=buildtree();
    cout<<"Height of the tree is: "<<height(root)<<endl;
    //Print_kth_level(root,3);
    Print_all_levels(root);
	return 0;
}