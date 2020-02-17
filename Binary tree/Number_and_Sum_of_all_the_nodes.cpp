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

int count(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ls=count(root->left);
    int rs=count(root->right);
    return ls+rs+1;
}

int sum(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ls=sum(root->left);
    int rs=sum(root->right);
    return ls+rs+root->data;
}
int main() 
{
	node* root=buildtree();
	cout<<count(root)<<endl;
	cout<<sum(root)<<endl;
	return 0;
}