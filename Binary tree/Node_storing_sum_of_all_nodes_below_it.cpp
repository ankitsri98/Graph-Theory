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

int sum_of_child(node* root)
{
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    //recursive part
    int l=sum_of_child(root->left);
    int r=sum_of_child(root->right);
    int d=root->data;
    root->data=l+r;
    cout<<"left:- "<<l<<" "<<"right:= "<<r<<" "<<"cur root value:= "<<d<<" "<<"update-root-val:= "<<root->data<<endl;
    return d+ root->data;
}
int main() 
{
	node* root=buildtree();
	cout<<sum_of_child(root)<<endl;
    
	return 0;
}