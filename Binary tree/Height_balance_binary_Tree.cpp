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

class hbpair{
    public:
    int height;
    bool balance;
};

hbpair hb_balance(node* root){
    hbpair p;
    if(root==NULL){
        p.height=0,p.balance=1;
        return p;
    }
    hbpair p1=hb_balance(root->left);
    hbpair p2=hb_balance(root->right);
    p.height=max(p1.height,p2.height)+1;
    p.balance=min(p1.balance,p2.balance);
    /*if(abs(p1.height-p2.height)<=1)
    p.balance=1;
    else
    p.balance=0;*/
    return p;
}


int main() 
{
	node* root=buildtree();
    
    hbpair p=hb_balance(root);
    cout<<p.height<<endl;
    cout<<p.balance<<endl;
	return 0;
}