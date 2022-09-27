
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
                // If both n1 and n2 are smaller than root,
        // then LCA lies in left
        while(root!=NULL){
        if (root->val > p->val && root->val > q->val)
           root = root->left;
 
        // If both n1 and n2 are greater than root,
        // then LCA lies in right
        else if (root->val < p->val && root->val < q->val)
                root = root->right;
            
        else break;

        
    }
        return root;
    }   
};


///recursive

/* Function to find LCA of n1 and n2.
The function assumes that both
n1 and n2 are present in BST */
node* lca(node* root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
 
    // If both n1 and n2 are smaller
    // than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
 
    // If both n1 and n2 are greater than
    // root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
 
    return root;
}
