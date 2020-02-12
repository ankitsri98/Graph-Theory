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

void bfs(node* root)//Complexity is O(N^2)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* x=q.front();
        q.pop();
        cout<<x->data<<" , ";
        if(x->left){//if there is further child then push
            q.push(x->left);
        }
        if(x->right){
            q.push(x->right);
        }
    }
    return;
}
int main() 
{
	node* root=buildtree();
    bfs(root);
	return 0;
}