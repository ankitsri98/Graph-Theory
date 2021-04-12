struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
void util(Node* root, stack<Node* > &st){//putting left diagonal in stack for comparison
    Node* cur=root;
    while(cur!=NULL){
        st.push(cur);
        cur=cur->left;
    }
}
class Solution{
  public:
    // Return a integer of integers having all the nodes in both the BSTs in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       stack<Node* > s1,s2;
       util(root1,s1);
       util(root2,s2);
       //initially put left view diagonal in the stack for comparison
       vector<int > v;
       while(!s1.empty() && !s2.empty()){
           Node* x=s1.top();
           Node* y=s2.top();
           //now applying the merge sort logic whichever node is popped then its right left diagonal is stored
           if(x->data<y->data){
               v.push_back(x->data);
               s1.pop();
               if(x->right!=NULL){
                   util(x->right,s1);
               }
           }
           else {
               v.push_back(y->data);
               s2.pop();
               if(y->right!=NULL){
                   util(y->right,s2);
               }
           }
       }
       while(!s1.empty()){
           Node* x=s1.top();
           s1.pop();
           v.push_back(x->data);
       }
       while(!s2.empty()){
           Node* x=s2.top();
           s2.pop();
           v.push_back(x->data);
       }
       return v;
    }
};

