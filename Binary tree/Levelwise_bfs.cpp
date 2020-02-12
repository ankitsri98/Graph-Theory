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
    queue<pair<node* ,int > > m;
    int l=0;
    m.push(make_pair(root,l));
    q.push(root);
    while(!q.empty()){
        node* x=q.front();
        q.pop();
        ++l;
        if(x->left){//if there is further child then push
            q.push(x->left);
            m.push(make_pair(x->left,l));
        }
        if(x->right){
            q.push(x->right);
            m.push(make_pair(x->right,l));
        }
    }
   /* while(!m.empty()){
        cout<<m.front().first->data<<"   "<<m.front().second<<endl;
        m.pop();
    }*/
    l=0;
    while(!m.empty()){
        pair<node*,int > p;
        p=m.front();
        node* x=p.first;
        int y=p.second;
        if(p.second==l)
        {
            cout<<x->data<<" ";
            m.pop();
        }
        else
        {
            l++;cout<<endl;
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