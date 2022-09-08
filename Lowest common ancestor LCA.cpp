class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        //
        if(root->val==p->val || root->val==q->val)
            return root;
        
        //leaf node
        if(!root->left and !root->right)
            return NULL;
        
        //search left and right 
        
        TreeNode *left=NULL,*right=NULL;
        if(root->left)
            left = lowestCommonAncestor(root->left,p,q);
        if(root->right)
            right = lowestCommonAncestor(root->right,p,q);
        //if it recieves non null from both sides , the root is LCA
        if(left and right)
            return root;
        
        // check if left subtree or right subtree is LCA
        return left==NULL?right:left;
    }
};
