int check(Node* root,bool &bi){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
     }
     
     int  a=check(root->left,bi);
     int b=check(root->right,bi);
     if((a+b)!=root->data){
         bi=0;
     }
     return root->data+a+b;
}
bool isSumTree(Node* root)
{
    bool bi=1;
    int x=check(root,bi);
    return bi;
     
}
