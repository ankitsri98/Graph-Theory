void connect(Node *p)
{
    queue<Node* > q;
    Node* ex=NULL;
    q.push(p);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();//using concept of NULL that tells me that now 1 level is over and new one is started 
        if(temp==NULL){
            ex=NULL;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
            continue;
        }
        else{
            //cout<<temp->data<<endl;
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if( temp->right){
                q.push(temp->right);
            }
            
            if(ex!=NULL){
                //cout<<ex->data<<" "<<temp->data<<endl;
                ex->nextRight=temp;
            }
            ex=temp;
        }
    }
}
