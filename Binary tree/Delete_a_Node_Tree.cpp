/*
In order to handle all of the cases, one way to delete a node is to:
Starting at the root, find the deepest and rightmost node in binary tree and node which we want to delete.
Replace the deepest rightmost node’s data with the node to be deleted.
Then delete the deepest rightmost node.

*/
// Function to delete the given deepest node 
// (d_node) in binary tree 
void deletDeepest(struct Node *root, struct Node *d_node) 
{ 
    queue<struct Node*> q; 
    q.push(root); 

    // Do level order traversal until last node 
    struct Node* temp; 
    while(!q.empty()) 
    { 
        temp = q.front(); 
        q.pop(); 

        if (temp->right) 
        { 
            if (temp->right == d_node) 
            { 
                temp->right = NULL; 
                delete(d_node); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 

        if (temp->left) 
        { 
            if (temp->left == d_node) 
            { 
                temp->left=NULL; // FILL IT BY null SO THAT LATER IT CAN BE FILLED WITH RIGHTMOST NODE DATA
                delete(d_node); 
                return; 
            } 
            else
                q.push(temp->left); 
        } 
    } 
} 

// Function to delete element in binary tree 
void deletion(struct Node* root, int key) 
{ 
    queue<struct Node*> q; 
    q.push(root); 

    struct Node *temp; 
    struct Node *key_node = NULL; 

    // Do level order traversal to find deepest 
    // node(temp) and node to be deleted (key_node) 
    while (!q.empty()) 
    { 
        temp = q.front(); 
        q.pop(); 

        if (temp->key == key) 
            key_node = temp; //KEEP THAT NODE

        if (temp->left) 
            q.push(temp->left); 

        if (temp->right) 
            q.push(temp->right); 
    } 

    int x = temp->key; //AT THE END OF LEVEL ORDER TRAVERSEL TEMP IS POINTING TO THE RIGHT MOST NODE
    deletDeepest(root, temp); 
    key_node->key = x; 
} 
