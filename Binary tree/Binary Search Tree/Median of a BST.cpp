void morris_traversal(Node* root, int &c){
    Node* cur=root;
    while(cur!=NULL){//no recursion so while is used to check at each node
        if(cur->left==NULL){//if left node does not exist
            c++;
            //cout<<cur->data<<endl;
            cur=cur->right;
        }
        else {
            Node* pre=cur->left;
            while(pre->right!=NULL && pre->right!=cur){//when one fails breaks and that is check further
                pre=pre->right;
            }
            if(pre->right==NULL){
                pre->right=cur;
                cur=cur->left;
            }
            else {
                pre->right=NULL;
                c++;
                //cout<<cur->data<<endl;
                cur=cur->right;
            }
        }
    }
}
void mt(Node* root, int &idx,int &a){
    Node* cur=root;
    while(cur!=NULL){
        if(cur->left==NULL){
            idx--;
            if(idx==0){
                a=cur->data;return;
            }
            //cout<<cur->data<<endl;
            cur=cur->right;
        }
        else {
            Node* pre=cur->left;
            while(pre->right!=NULL && pre->right!=cur){
                pre=pre->right;
            }
            if(pre->right==NULL){
                pre->right=cur;
                cur=cur->left;
            }
            else {
                pre->right=NULL;
                idx--;
                if(idx==0){
                    a=cur->data;return;
                }
                //cout<<cur->data<<endl;
                cur=cur->right;
            }
        }
    }
}
float findMedian(struct Node *root)
{
    int c=0;
    float x=0;
    morris_traversal(root,c);
    //cout<<c<<endl;
    if(c%2!=0){
        int a=0,idx=(c+1)/2;;
        mt(root,idx,a);
        x=a/1.0;
        //cout<<idx<<" "<<a<<" "<<x<<endl;
        return x;
    }
    else{
        int a=0,b=0,idx=c/2;
        mt(root,idx,a);
        idx++;
        mt(root,idx,b);
        x=(a+b)/2*1.0;
        //cout<<idx<<" "<<a<<" "<<b<<" "<<x<<endl;
        return x;
    }
    
}
