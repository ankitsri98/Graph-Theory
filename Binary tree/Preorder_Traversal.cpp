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

void printtree(node* root)
{
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printtree(root->left);
    printtree(root->right);
}
int main() 
{
	node* root=buildtree();
	printtree(root);
    
	return 0;
}
