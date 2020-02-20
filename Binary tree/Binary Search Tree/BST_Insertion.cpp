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
//Accepts the old root node and returns the new root node
node* insert_in_bst(node* root,int data){
    //base case
    if(root==NULL){
        return new node(data);
        //when we create data using data using new then it automatically returns the address
    }
    //rec casse
    if(data<=root->data){
        root->left=insert_in_bst(root->left,data);
    }
    else{
        root->right=insert_in_bst(root->right,data);
    }
    return root;
}
node* buildtree(){
    
    int d;
    cin>>d;
    
    node* root=NULL;
    while(d!=-1){
        root=insert_in_bst(root,d);
        cin>>d;
    }
    return root;
    
}
 bool search(node* root,int s){
     if(root==NULL){
         return false;
     }
     if(root->data==s){
         return true;
     }
     //rec calls
     if(s<=root->data){
         return search(root->left,s);
     }
     else{
         if(s>root->data){
             return search(root->right,s);
         }
     }
 }

void inorder(node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" , ";
    inorder(root->right);
}

int main() 
{
	node* root=buildtree();
	inorder(root);
	cout<<endl;
	int s;
	cin>>s;
	cout<<search(root ,s)<<endl;
	//deleteX(root ,s);
	inorder(root);
}