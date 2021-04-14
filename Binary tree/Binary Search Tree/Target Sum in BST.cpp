void f1(TreeNode* root,stack<TreeNode* > &s1){
    TreeNode* cur=root;
    while(cur!=NULL){
        s1.push(cur);
        cur=cur->left;
    }
}
void f2(TreeNode* root,stack<TreeNode* > &s2){
    TreeNode* cur=root;
    while(cur!=NULL){
        s2.push(cur);
        cur=cur->right;
    }
}
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        //THIS PROBLEM CAN ALSO BE DONE AS
        //FIND INORDER TRAVERSAL WHICH WILL BE SORTED THEN APPLY 2 SUM SORTED ARRAY LOGIC
        //BUT I WILL DO IT DIRECTLY
        /*unordered_map<int ,int > mp;
        return calc(root,k,mp);*/
        if(!root)return false;
        stack<TreeNode* > s1,s2;
        f1(root,s1);
        f2(root,s2);
        int f=1;
        
        while(s1.empty()==0 && s2.empty()==0 && s1.top()->val<s2.top()->val){
            TreeNode* x=s1.top();
            TreeNode* y=s2.top();
            int z=x->val + y->val;
            
            if(z==k)return true;
            else if(z<k){
                s1.pop();
                if(x->right!=NULL){
                    f1(x->right,s1);
                }
            }
            else if(z>k){
                s2.pop();
                if(y->left!=NULL){
                    f2(y->left,s2);
                }
            }
        }
        return false;
    }
};
