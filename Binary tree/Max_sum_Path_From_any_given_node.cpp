#include<bits/stdc++.h>
using namespace std;
int sum=0;
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
node* buildbst(node* root,int* arr,int s,int e){
    if(e<s)
    return NULL;
    int mid=(e+s)/2;
   	root=new node(arr[mid]);
	root->left=buildbst(root->left,arr,s,mid-1);
	root->right=buildbst(root->right,arr,mid+1,e);
    
    return root;
}
node* buildtree(int n){
    
    node* root=NULL;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    root=buildbst(root,a,0,n-1);
    
    return root;
}
/*node* buildtree(){
    string s;
	cin>>s;
	if(s=="false"){
		return NULL;
	}
	else if(s=="true"){
		string d;cin>>d;
		node* root=new node(d);
		root->left=buildtree();
		root->right=buildtree();
		return root;
	}
	node* root=new node(s);
	root->left=buildtree();
	root->right=buildtree();
	return root;
}*/
int maxval=0;
int max_sum_path(node* root){//MAX SUM DIST FROM GIVEN ROOT TO THE ANY NODE
    if(root==NULL){
        return 0;
    }
    int l=max_sum_path(root->left);
    int r=max_sum_path(root->right);

    int a=root->data;
    int b=l+root->data;
    int c=r+root->data;
    int d=l+r+root->data;

    maxval=max(a,max(b,max(c,d)));
    return max(l,max(r,0))+root->data;
}
int val=0;
void inorder(node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    val=root->data;
    //cout<<root->data<<endl;
    root->data=sum;
    sum=sum-val;
    //cout<<"val: "<<val<<" upadted root data: "<<root->data<<" sum: "<<sum<<endl;
    inorder(root->right);
}
void preorder(node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);    
}
int main() 
{
	
    int n;
        cin>>n;
        node* root=buildtree(n);
        //cout<<sum<<endl;
        //inorder(root);
        //preorder(root);
        int x=max_sum_path(root->right);
        cout<<maxval;
        cout<<endl;

	return 0;
}

