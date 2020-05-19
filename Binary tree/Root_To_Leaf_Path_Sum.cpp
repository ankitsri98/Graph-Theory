/*
Given a Binary Tree and a sum s, 
your task is to check whether there is a 
root to leaf path in that tree with the following sum .
*/
bool hasPathSum(Node *node, int sum) {
    
    //so the logic for these  type of problem is to use the top down
    //approach decreasing the sum at each node
    
    if(node==NULL){
        return false ; //because the counter would reach here only if it got
                       //false in the previous condition
    }
    sum=sum-node->data;
    if(sum==0 && node->left==NULL && node->right==NULL){
        return true ;
    }
    
    bool a=hasPathSum(node->left,sum);
    bool b=hasPathSum(node->right,sum);
    
    return a|b;//OR is used coz if ever i got 1 then 1 path exists 
}
