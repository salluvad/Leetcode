void mirror(struct Node* node) 
{
    if (node == NULL) 
        return; 
    else
    {
        struct Node* temp;
          
        /* do the subtrees */
        mirror(node->left);
        mirror(node->right);
      
        /* swap the pointers in this node */
        temp     = node->left;
        node->left = node->right;
        node->right = temp;
    }
} 



//////iterative
using queue and level order traversal , at each level swap left and right pointers


void mirror(Node* root)
{
    if (root == NULL)
        return;
  
    queue<Node*> q;
    q.push(root);
  
    // Do BFS. While doing BFS, keep swapping
    // left and right children
    while (!q.empty())
    {
        // pop top node from queue
        Node* curr = q.front();
        q.pop();
  
        // swap left child with right child
        swap(curr->left, curr->right);
  
        // push left and right children
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}
