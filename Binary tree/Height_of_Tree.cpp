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

void print_Preorder(node* root)
{
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    print_Preorder(root->left);
    print_Preorder(root->right);
}

void print_Inorder(node* root)
{
    if(root==NULL){
        return;
    }
    print_Inorder(root->left);
    cout<<root->data<<" ";
    print_Inorder(root->right);
}

void print_Postorder(node* root)//bottom up
{
    if(root==NULL){
        return;
    }
    print_Postorder(root->left);
    print_Postorder(root->right);
    cout<<root->data<<" ";
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
int main() 
{
	node* root=buildtree();
	cout<<"preorder"<<endl;
	print_Preorder(root);
	cout<<endl;
	cout<<"inorder"<<endl;
	print_Inorder(root);
	cout<<endl;
	cout<<"postorder"<<endl;
	print_Postorder(root);
    
    cout<<"HEight of the tree is: "<<height(root)<<endl;
	return 0;
}