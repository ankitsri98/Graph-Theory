#include <bits/stdc++.h>
using namespace std;
//build tree
//diameter
//check balance
//views
//check bst
//top view
//vertical traversal
//LCA
class node{
public:
    int data;node* left;node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* build_tree(node* root,int s,int e,int *arr){
    if(e<s)return NULL;
    int mid=(s+e)/2;
    root= new node(arr[mid]);
    root->left=build_tree(root->left,s,mid-1,arr);
    root->right=build_tree(root->right,mid+1,e,arr);
    return root; 
    }
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}
void level_wise(node* root){
    queue<node* > q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* x=q.front();
        q.pop();
        if(x==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<x->data<<" ";
            if(x->left){
                q.push(x->left);
            }
            if(x->right){
                q.push(x->right);
            }
        }
    }
}
class ppair{
public:
    int h,d;
};

ppair dia(node* root){
    ppair p;
    if(root==NULL){
        p.h=0;
        p.d=0;
        return p;
    }
    ppair l=dia(root->left);
    ppair r=dia(root->right);
    p.h=max(l.h,r.h)+1;
    p.d=max(l.d, max(r.d,l.h+r.h));
    return p;
}
bool check_bst(node* root, int ml,int mr){
    if(root==NULL)return true;

    bool l=check_bst(root->left,ml,root->data);
    bool r=check_bst(root->right,root->data,mr);

    if((root->data>=ml && root->data<=mr )&& l && r){
        return true;
    }
    return false;
}
map<int ,int > mp;
void top_view(node* root,int d){
    queue<pair<node*,int > > q;
    q.push({root,d});
    while(!q.empty()){
        pair<node* ,int > x=q.front();
        q.pop();
        if(mp.find(x.second)==mp.end()){//FOR BOTTOM VIEW REMOVE IF
            mp[x.second]=x.first->data;
        }
        if(x.first->left){
            q.push({x.first->left,x.second-1});
        }
        if(x.first->right){
            q.push({x.first->right,x.second+1});
        }
    }
}
map<int , vector<int > > mx;
void vertical_traversal(node* root,int d){
    queue<pair<node*,int > > q;
    q.push({root,d});
    while(!q.empty()){
        pair<node* ,int > x=q.front();
        q.pop();
        mx[x.second].push_back(x.first->data);
        if(x.first->left){
            q.push({x.first->left,x.second-1});
        }
        if(x.first->right){
            q.push({x.first->right,x.second+1});
        }
    }
}
node* LCA(node* root, int a,int b){
    if(root==NULL)return NULL;
    if(root->data==a || root->data==b)return root;

    node* x=LCA(root->left,a,b);
    node* y=LCA(root->right,a,b);

    if(x==NULL && y==NULL){
        return NULL;
    }
    else if(x!=NULL && y!=NULL){
        return root;
    }
    else {
        return (x!=NULL)? x:y;
    }
}
int main() {
    node* head=NULL;
    int arr[]={1,2,3,4,5,6,7,8,9};
    node* root=build_tree(head,0,8,arr);
    //pre_order(root);
    //cout<<endl;
    level_wise(root);
    //ppair xx=dia(root);
    //cout<<xx.d<<endl;
    //cout<<check_bst(root,INT_MIN,INT_MAX)<<endl;
    //level_wise(root);
    /*top_view(root,0);
    for(auto i:mp){
        cout<<i.second<<" ";
    }
    cout<<endl;*/
    vertical_traversal(root,0);
    for(auto i : mx){
        for(auto j : i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    node* l=LCA(root,1,6);
    cout<<"LCA IS: "<<l->data<<endl;
    //level_wise(root);

}
