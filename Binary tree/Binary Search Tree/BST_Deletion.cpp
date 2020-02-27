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
 
 node* deleteX(node* root,int d)
 {
     if(root==NULL)
     {
         return NULL;//mean parent me NULL attach kardo
     }
     else if(d==root->data){
         if((root->left==NULL && root->right==NULL)){//CASE:1
             delete root;
             return NULL;
         } 
         if((root->left==NULL && root->right!=NULL)){//CASE 2:
             node* temp=root->right;
             delete root;
             return temp;//this value is returned to parent of root
         }
         if((root->left!=NULL && root->right==NULL)){
             node* temp=root->left;
             delete root;
             return temp;
         }
         // NOW case 3 
         if((root->left!=NULL && root->right!=NULL)){//CASE:1
             node* temp=root->right;
             
             while(temp->left!=NULL){
                 temp=temp->left;
             }
             root->data=temp->data;
             root->right=deleteX(root->right,temp->data);//root->right is a subtree in which we have to delete temp
             return root;
         }
     }
     //rec calls
     else if(d<root->data){
         root->left= deleteX(root->left,d);//we are storing coz we want the change back to be updated in all nodes
         return root;
     }
     else{
         if(d>root->data){
             root->right=deleteX(root->right,d);
             return root;
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
	deleteX(root ,s);
	inorder(root);
}